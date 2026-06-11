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
 bool ok=true;
  string s;
  cin>>s;
  ok= s[0]=='A';
  int cnt=0;
  int n=s.size();
  for(int i=2;i<=s.size()-2;i++){
    if(s[i]=='C')cnt++;
    else if(s[i]<'a') ok=false;
  }
  if(cnt!=1) ok=false;
  if(s[1]<'a') ok=false;
  if(s[n-1]<'a') ok=false;
  
  if(ok) cout<<"AC"<<endl;
  else cout<<"WA"<<endl;
}








