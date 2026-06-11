#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int a,b;
  cin>>a>>b;
  string s;
  cin>>s;
  bool ans=true;
  rep(i,0,s.size()){
   if(i<a){
     if(s[i]<'0'||s[i]>'9')ans=0;
   }
   else if(i==a){
    if(s[i]!='-')ans=false; 
   }
    else{
      if(s[i]<'0'||s[i]>'9'){
        ans=0; 
        //cout<<1<<endl;
      }
    }
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}