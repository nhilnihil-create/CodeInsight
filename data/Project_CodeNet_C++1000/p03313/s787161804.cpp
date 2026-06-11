#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int n;
pair<pair<int,int>,int>solve(vector<pair<pair<int,int>,int>> &ma,vector<int> &a,int key){
  if(ma[key].first.first>=0)return ma[key];
  else{
    int s=0;
    pair<int,int> f=make_pair(a[key],key);
    rep(i,n){
      if(key&(1<<i)){
        pair<pair<int,int>,int> w=solve(ma,a,key-(1<<i));
        int c=w.first.first;
        int l=w.second;
        if(f.second!=w.first.second){
          if(c>f.first){
            s=f.first;
            f=make_pair(c,w.first.second);
          }
          else if(c>s){
            s=c;
          }
        }
        if(l>s){
          s=l;
        }
      }
    }
    ma[key]=make_pair(f,s);
    return make_pair(f,s);
  }
}
int main(){
  cin  >> n;
  int o=1;
  rep(i,n)o=o*2;
  vector<pair<pair<int,int>,int>> ma(o,make_pair(make_pair(-1,-1),-1));
  vector<int> a(o,-1);
  rep(i,o)cin >> a[i];
  ma[0]=make_pair(make_pair(a[0],0),-1);
  rep(i,n){
    int y=(1<<i);
    if(a[0]>a[y])ma[y]=make_pair(make_pair(a[0],0),a[y]);
    else ma[y]=make_pair(make_pair(a[y],y),a[0]);
  }
  solve(ma,a,o-1);
  int ans=0;
  rep(i,o-1){
    ans=max(ans,ma[i+1].first.first+ma[i+1].second);
    cout << ans << endl;
  }
}  
