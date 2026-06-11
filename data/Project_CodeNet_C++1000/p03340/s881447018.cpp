#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N;
  cin >> N;
  vl A(N);
  rep(i, N) cin >> A[i];

  ll left = 0, right = 0;
  ll ans = 1;
  ll calc = A[0];

  while(right < N - 1){
    if((calc ^ A[right + 1]) == (calc + A[right + 1])){
      right++;
      calc += A[right];
      ans += right - left + 1;
    } else{
      calc -= A[left];
      left++;

      if(left > right){
	right = left;
	calc = A[left];
	ans++;
      }
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
