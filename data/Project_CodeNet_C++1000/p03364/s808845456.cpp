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
  cin >> n;
  vstring mass(n);
  rep(i,n) cin >> mass[i];
  int ans = 0;
  rep(i,n){
    bool flag = true;
    rep(j,n){
      rep(s,n){
        if(mass[j][s] != mass[s][j]) flag = false;
      }
    }
    if(flag) ans += n;
    vstring newmass(n);
    newmass[0] = mass[n-1];
    rep1(j,n){
      newmass[j] = mass[j-1];
    }
    mass = newmass;
  }
  cout << ans << endl;
}