#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  vector<ll> A(n);
  vector<ll> B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  ll bowl = 0;
  ll need = 0;
  rep(i, n){
    if(A[i] > B[i]){
      need += A[i] - B[i];
    }else{
      bowl += (B[i] - A[i]) / 2;
    }
  }
  if(bowl >= need) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
  
  