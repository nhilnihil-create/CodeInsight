#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
int memo[110000];
int main() {
int n,m;
  cin>>n>>m;
  vin q(m),y(m);
  rep(i,m) cin>>q[i]>>y[i];
  ////
  vector<pair<P,int>> p(m);
  rep(i,m){
   p[i].first=make_pair(q[i],y[i]);
    p[i].second=i;
    //cout<<p[i].first<<endl;
  }
  sort(all(p));
  int c=0;//県
  int num=0;//順番
  rep(i,m){
         if(c==p[i].first.first){
           num++;
           p[i].first.second=num;
         }
         else{
           num=1;
           c=p[i].first.first;
           p[i].first.second=num;
         }
  }
  
  rep(i,m){
   swap(p[i].first.first,p[i].second);
    
   swap(p[i].first.second,p[i].second); 
  }
  sort(all (p));
  for(auto v: p){
   // cout<<v.first.first<<endl;
    string a,b;
    a=to_string(v.first.second);
    b=to_string(v.second);
    cout << setfill('0') << right << setw(6) << a; // "0012"
     cout << setfill('0') << right << setw(6) << b; // "0012"
   cout<<endl; 
  }
}








