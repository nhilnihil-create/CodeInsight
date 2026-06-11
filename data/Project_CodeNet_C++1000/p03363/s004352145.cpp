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
  vint A(n);
  rep(i,n) cin >> A[i];
  vint S(n+1);
  S[0] = 0;
  rep1(i,n+1){
    S[i] = S[i-1] + A[i-1];
  }
  //rep(i,n+1) cout << S[i] << " ";
  sort(S.begin(),S.end());
  int ans = 0;
  int count = 1;
  rep(i,n){
    if(S[i] == S[i+1]){
      count++;
      if(i == n-1){
        ans += count*(count-1)/2;
      }
    }
    else{
      ans += count*(count-1)/2;
      count = 1;
    }
  }
  cout << ans << endl;
}