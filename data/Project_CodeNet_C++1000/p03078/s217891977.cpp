//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll x,y,z,k;cin>>x>>y>>z>>k;
  vl a(x),b(y),c(z);
  rep(i,x)cin>>a[i];
  rep(i,y)cin>>b[i];
  rep(i,z)cin>>c[i];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  priority_queue<tuple<ll,ll,ll,ll> >q;
  set<tuple<ll,ll,ll,ll> >S;
  q.push(make_tuple(a[0]+b[0]+c[0],0,0,0));
  S.insert(make_tuple(a[0]+b[0]+c[0],0,0,0));
  ll count=0;
  while(true){
    T t=q.top();
    q.pop();
    cout<<get<0>(t)<<endl;
    count++;
    if(count==k)return 0;
    ll i=get<1>(t);
    ll j=get<2>(t);
    ll k=get<3>(t);
    if(!S.count(make_tuple(a[i+1]+b[j]+c[k],i+1,j,k))&&i!=x-1){
      S.insert(make_tuple(a[i+1]+b[j]+c[k],i+1,j,k));
      q.push(make_tuple(a[i+1]+b[j]+c[k],i+1,j,k));
    }
    if(!S.count(make_tuple(a[i]+b[j+1]+c[k],i,j+1,k))&&j!=x-1){
      S.insert(make_tuple(a[i]+b[j+1]+c[k],i,j+1,k));
      q.push(make_tuple(a[i]+b[j+1]+c[k],i,j+1,k));
    }
    if(!S.count(make_tuple(a[i]+b[j]+c[k+1],i,j,k+1))&&k!=x-1){
      S.insert(make_tuple(a[i]+b[j]+c[k+1],i,j,k+1));
      q.push(make_tuple(a[i]+b[j]+c[k+1],i,j,k+1));
    }
  }
}