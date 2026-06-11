#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
string s,t;
  cin>>s>>t;
  int n=s.size();
  map<char,int> mas,mat;
  rep(i,0,n){
   mas[s[i]]++;
   mat[t[i]]++;
  }
  int cnt[2][220000];
  rep(i,0,n){
   rep(j,0,2){
     cnt[j][i]=0; 
   }
  }
  for(auto v:mas){
    cnt[0][v.second]++; 
  }
  for(auto v:mat){
   cnt[1][v.second]++; 
  }
  bool ok=true;
  rep(i,0,n){
    if(cnt[0][i]!=cnt[1][i]) ok=false;
  }
  if(ok) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}