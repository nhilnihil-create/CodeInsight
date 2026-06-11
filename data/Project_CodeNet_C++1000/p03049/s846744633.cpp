#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define answer cout << ans << endl;
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;

signed _main(){
  int N; cin >> N;
  queue<string> a,b,ba,other;
  rep(i,N){
    string s; cin >> s;
    if(s[0]=='B' && s[s.size()-1]=='A') ba.push(s);
    else if(s[0]=='B') b.push(s);
    else if(s[s.size()-1]=='A') a.push(s);
    else other.push(s);
  }
  string S="";
  string s;
  if(!a.empty()){
    s=a.front();
    S=S+s;
    a.pop();
  }
  while(!ba.empty()){
    s=ba.front();
    S=S+s;
    ba.pop();
  }
  if(!b.empty()){
    s=b.front();
    S=S+s;
    b.pop();
  }
  while(!a.empty() && !b.empty()){
    s=a.front();
    S=S+s;
    a.pop();
    s=b.front();
    S=S+s;
    b.pop();
  }
  while(!a.empty()){
    s=a.front();
    S=S+s;
    a.pop();
  }
  while(!b.empty()){
    s=b.front();
    S=S+s;
    b.pop();
  }
  while(!other.empty()){
    s=other.front();
    S=S+s;
    other.pop();
  }
  //cout << S << endl;
  int size=0,ans=0;
  rep(i,S.size()+1){
    if(i+1<S.size() && S[i]=='A' && S[i+1]=='B'){
      size++;
      i++;
    }
  }
  cout << size << endl;
  return 0;
}
