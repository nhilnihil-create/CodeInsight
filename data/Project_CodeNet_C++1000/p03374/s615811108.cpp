#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
struct Grid{int x,y,t;};
struct Edge{int to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  Graph(int n):E(n){E.resize(n);V=n;}
  void add_edge(int from,int to,int cost){E[from-1].pb({to-1,cost});}
};
ll sum[100010]={};
class segTree{
public:
  const ll Inf = llINF;
  ll n=0;
  vector<ll>node;
  segTree(ll nn){
    n=1;
    while(n<nn)n*=2;
    node.resize(n*2);
    //initializer
    //ex. RMQ
    init(-Inf);
  }
  
  void init(ll hoge){//RMQ
    for(int i=0;i<node.size();i++)node[i]=hoge;
  }

  void init(vector<ll> hoge){//RSQ
    for(int i=0;i<hoge.size();i++)update(i,hoge[i]);
  }

  void update(int index,const ll value){
    index+=n;
    node[index]=value;//RMQ
    while(index > 0){
      index/=2;
      node[index] = ope(node[2*index],node[2*index+1]);
    }
  }
  ll find(int l,int r){
    if(l == r) return node[r+n];
    l += n; r += n;
    ll ans = -Inf;
    for(; l <= r;l >>=1, r >>=1){
      if(r == l){ans=ope(ans,node[l]); return ans;}
      if(r%2 == 0) ans=ope(ans,node[r]),--r;
      if(l%2) ans=ope(ans,node[l]),++l;
    }
    return ans;
  }
  ll ope(const ll a,const ll b){
    return max(a,b);
  }
};

int main(){
  ll n,c;cin>>n>>c;
  vector<ll>le(n+10),ri(n+10);
  vector<ll>pll(n);
  vector<ll>pl(n);
  for(int i=0;i<n;i++){
    
    cin>>pll[i]>>pl[i];
    le[i+1]=pl[i]+le[i];
  }
  for(int i=n;i>0;i--){
    ri[i]=ri[i+1]+pl[i-1];
  }
  segTree seg(n+5),seg3(n+5);
  for(int i=1;i<=n;i++){
    seg.update(i-1,le[i]-pll[i-1]);
    seg3.update(i-1,ri[i]-(c-pll[i-1]));
  }
    ll ans=0;
  for(int i=0;i<n;i++){
      ans=max(seg.find(i,i),ans);ans=max(seg3.find(i,i),ans);
  }
  //cout<<endl;

  for(int i=0;i<n;i++){
   // cout<<le[i+1]-2*pll[i]<<" "<<seg3.find(i+1,n-1)<<endl;
    //cout<<ri[i+1]-2*(c-pll[i])<<" "<<seg.find(0,i-1)<<endl;
    ans=max(ans,max(0LL,le[i+1]-2*pll[i])+max(0LL,seg3.find(i+1,n-1)));
    ans=max(ans,max(0LL,ri[i+1]-2*(c-pll[i]))+max(seg.find(0,i-1),0LL));
  }
  cout<<ans<<endl;
  return 0;
}