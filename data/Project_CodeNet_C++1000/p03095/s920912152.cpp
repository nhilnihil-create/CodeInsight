#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int n;
  string s;
  cin >> n >> s;
  vint eng(26);
  rep(i,n){
    eng[s[i]- 'a']++;
  }
  int ans = 1;
  rep(i,26){
    ans *= eng[i]+1;
    ans %= MOD;
  }
  cout << ans - 1 << endl; 
}