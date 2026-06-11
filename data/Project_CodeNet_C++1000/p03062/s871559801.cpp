#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

ll pow_mod(ll a, ll n, ll MOD){
  ll m[60]; m[0]=a; // m[i] : a^(2^i)をMODで割った余り
  rep(i,59) m[i+1] = (m[i]*m[i])%MOD;

  ll retval = 1;
  bitset<60> s(n);
  rep(i,60) if (s.test(i)) (retval *= m[i]) %= MOD;

  return retval; 
}

int main(){
  int N; cin >> N;
  int A[N];
  int ABS[N];
  int cnt = 0;
  ll ans = 0;
  rep(i,N) {
    cin >> A[i];
    ans += abs(A[i]);
    ABS[i] = abs(A[i]);
    if (A[i]<=0) cnt++;
  }
  if (cnt%2){
    int MIN = min_element(ABS,ABS+N) - ABS;
    if (A[MIN]<=0) ans = ans - abs(A[MIN]) + A[MIN];
    else ans = ans - abs(A[MIN]) - A[MIN];
  }
  cout << ans << endl;






  // cout << fixed << setprecision(10);
  
  return 0;
}
