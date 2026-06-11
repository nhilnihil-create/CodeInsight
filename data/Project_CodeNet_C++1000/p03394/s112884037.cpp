#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define substr(s,f,t) (s.substr(f-1,t-f+1))
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
struct Grid{ll x,y,t;};
struct Edge{ll to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=201010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(ll from,ll to,ll cost){E[from].pb({to,cost});}
};
ll gcd(ll a,ll b){
    ll r=a%b; 
    while(r!=0){a=b;b=r;r=a%b;}
    return b;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  if(n<=5){
    if(n==3){cout<<2<<" "<<5<<" "<<63<<endl;return 0;}
    int ki[10]={6,2,10,3,9,4};
    int gu[10]={2,10,3,9,4,8};
    if(n%2){
      for(int i=0;i<n;i++)
	cout<<ki[i]<<" ";
      cout<<endl;
    }else{
      for(int i=0;i<n;i++)
	cout<<gu[i]<<" ";
      cout<<endl;
    }
    return 0;
  }
  vvi num(10);
  num[0].pb(0);
  for(int i=2;i<=30000;i++)
    num[i%6].pb(i);
  // if(n<=5){
    ll now=2;
    vi ans;
    ll sum=0;
    ll cnt[10]={};
    cnt[0]++;
    for(int i=0;i<n;i++){
      if(now==1||now==5){now=(now+1)%6;}
      ans.pb(num[now][cnt[now]]);
      sum+=num[now][cnt[now]];
      cnt[now]++;
      now++;
    }
    // cout<<sum<<endl;
    if(sum%6==0){
      for(ll a:ans)cout<<a<<" ";
      cout<<endl;
    }else{
      if(sum%6==5){
	for(int i=0;i<ans.size();i++)
	  if(ans[i]%6==3){ans.erase(ans.begin()+i);break;}
	ans.pb(num[4][cnt[4]]);
      }else if(sum%6==3){
	for(int i=0;i<ans.size();i++)
	  if(ans[i]%6==3){ans.erase(ans.begin()+i);break;}
	ans.pb(num[0][cnt[0]]);
      }else if(sum%6==2){
	for(int i=0;i<ans.size();i++)
	  if(ans[i]%6==2){ans.erase(ans.begin()+i);break;}
	ans.pb(num[0][cnt[0]]);
      }
      for(ll a:ans)cout<<a<<" ";
      cout<<endl;
    }/*
  }else{
    ll now=0;
    vi ans;
    ll sum=0;
    ll cnt=0;
    for(int i=0;i<n;i++){
      if(now==1||now==5){now=(now+1)%6;if(now==0)cnt++;}
      ans.pb(num[now][cnt]);
      sum+=num[now][cnt];
      now++;
    }
    if(sum%6==0){
      for(ll a:ans)cout<<a<<" ";
      cout<<endl;
    }else{
      sum-=ans.back();
      for(ll a:ans)cout<<a<<" ";
      cout<<num[6-sum%6][cnt+1]<<endl;
    }
    }*/
  return 0;
}
