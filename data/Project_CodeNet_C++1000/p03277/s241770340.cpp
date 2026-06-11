#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int zero_P=100005;
struct segtree{
private:
  vector<ll> node;
  int siz;
public:
  segtree(vector<ll> v){
    int n=v.size();
    siz=1;
    while(siz<n) siz*=2;
    node.resize(siz*2,0);
    for(int i=0;i<n;i++) node[i+siz-1]=v[i];
    for(int i=siz-2;i>=0;i--) node[i]=node[i*2+1]+node[i*2+2];
  }
  void add(int a,int x){
    a+=siz-1;
    node[a]+=x;
    while(a>0){
      a=(a-1)/2;
      node[a]=node[2*a+1]+node[2*a+2];
    }
  }
  ll q_sum(ll a,ll b,ll x,ll l,ll r){
    if(r<=a||b<=l) return 0;
    if(a<=l&&r<=b) return node[x];
    ll lsum=q_sum(a,b,2*x+1,l,(l+r)/2);
    ll rsum=q_sum(a,b,2*x+2,(l+r)/2,r);
    return lsum+rsum;
  }
  ll sum(ll a){
    return q_sum(a,siz,0,0,siz);
  }
};
int main(){
  ll n;
  cin>>n;
  ll border=(n*(n-1)/2+n)/2+1;
  vector<ll> vec,sort_vec;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    vec.push_back(a);
    sort_vec.push_back(a);
  }
  sort(sort_vec.begin(),sort_vec.end());
  sort_vec.erase(unique(sort_vec.begin(),sort_vec.end()),sort_vec.end());
  ll l=-1,r=sort_vec.size()-1;
  while(r-l>1){
    ll mid=(l+r)/2;
    ll mid_v=sort_vec[mid];
    ll kans=0;
    vector<ll> delta(200010,0);
    ll under=0,over=0;
    for(int i=0;i<n;i++){
      if(vec[i]<=mid_v) under++;
      else over++;
      delta[under-over+zero_P]++;
    }
    segtree seg=segtree(delta);
    under=0;
    over=0;
  //  cout<<mid<<" "<<mid_v<<" K:";
    for(int i=0;i<n;i++){
      kans+=seg.sum(zero_P+1+under-over);
      if(vec[i]<=mid_v) under++;
      else over++;
      seg.add(under-over+zero_P,-1);
    //  cout<<kans<<" ";
    }
    if(kans<border) l=mid;
    else r=mid;
    //cout<<kans<<endl;
  }
  cout<<sort_vec[r]<<endl;
}
