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
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009
using P = pair<int,int>;
 
int main() {
  int n;
  cin >> n;
  vint A(n);
  vint B(n);
  rep(i,n) cin >> A[i];
  rep(i,n) cin >> B[i];
  ll ans = 0;
  rep(i,n){
    if(A[i] < B[i]){
      ans += (B[i] - A[i])/2;
    }
    else{
      ans -= A[i] - B[i];
    }
  }
  if(ans < 0) cout << "No" << endl;
  else cout << "Yes" << endl;
}