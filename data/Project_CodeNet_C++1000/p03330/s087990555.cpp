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
#define INF 100000000000000009
#define MOD 1000000007
#define int long long
using P = pair<int,int>;
signed main(){
  int n,c;
  cin >> n >> c;
  vvint D(c,vint(c));
  rep(i,c) rep(j,c) cin >> D[i][j];
  vvint C(n,vint(n));
  rep(i,n) rep(j,n){
    cin >> C[i][j];
    C[i][j]--;
  }
  vint one(c);
  vint two(c);
  vint three(c);
  rep(i,n) rep(j,n){
    if((i + j + 2) % 3 == 1){
      one[C[i][j]]++;
    }
    if((i + j + 2) % 3 == 2){
      two[C[i][j]]++;
    }
    if((i + j + 2) % 3 == 0){
      three[C[i][j]]++;
    }
  }
  int ans = INF;
  rep(i,c) rep(j,c) rep(s,c){
    if(i != j && i != s && j != s){
      int temp = 0;
      rep(t,c){
        temp += one[t] * D[t][i];
        temp += two[t] * D[t][j];
        temp += three[t] * D[t][s];
      }
      ans = min(ans,temp);
    }
  }
  cout << ans << endl;
}