#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1<<30;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
int main(){
  string s; cin >> s;
  string t="";
  rep(i,0,s.size()-1){
    if(s[i]=='B'&&s[i+1]=='C'){
      t += 'X';
      i++;
    }else{
      t += s[i];
    }
  }
  vector<int> v(t.size()+1,0);
  ll cnt=0, ans = 0;
  rep(i,0,t.size()){
    if(t[i]=='A') cnt++;
    else if(t[i]=='X') ans += cnt;
    else cnt = 0;
  }
  cout << ans << endl;
  return 0;
}
