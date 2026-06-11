#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define P pair<int,int>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
template<class T> inline bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  vi b(n+1),w(n+1);
  rep(i,n){
    b[i+1] = (s[i]=='#');
    w[i] = (s[i]=='.');
  }
  rep(i,n){
    b[i+1] += b[i];
    w[i+1] += w[i];
  }
  int ans = INF;
  rep(i,n+1) chmin(ans,b[i]+w[n]-w[i]);
  cout << ans;
  cout << endl;
  return 0;
}
