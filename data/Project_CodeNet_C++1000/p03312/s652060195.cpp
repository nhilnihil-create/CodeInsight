#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n';
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll POSITIVE_INFINITY = 9223372036854775807;
const ll NEGATIVE_INFINITY = -9223372036854775807;
const ll MOD = 1000000007;
const ld PI = acos(-1.0);

template <typename T> inline T bigMod(T A,T B,T M = MOD){A %= M;T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}
template <typename T> inline T invMod (T A,T M = MOD){return bigMod(A,M-2,M);}

const int N = 200005;

int main(){
  FASTER;
  int n;
  cin >> n;
  int ar[n + 5];
  for (int i = 1; i <= n; i++){
    cin >> ar[i];
  }
  ll sum[n + 5];
  sum[0] = 0;
  for (int i = 1; i <= n; i++){
    sum[i] = sum[i - 1] + ar[i];
  }
  vector<ll>tmp;
  ll x, y;
  auto get_sum = [&] (int l, int r){
    return sum[r] - sum[l - 1];
  };
  auto F = [&](int L, int R){
    int l = L;
    int r = R;
    ll mn = 1e15;
    while (l <= r){
      int mid = (l + r) >> 1;
      ll sum_right = get_sum(mid + 1, R);
      ll sum_left = get_sum(L, mid);
      if (sum_left < sum_right){
        l = mid + 1;
      } else {
        r = mid - 1;
      }
      if (abs(sum_left - sum_right) < mn){
        mn = abs(sum_left - sum_right);
        x = sum_left;
        y = sum_right;
      }
    }
    tmp.push_back(x);
    tmp.push_back(y);
  };
  ll ans = 1e18;
  for (int i = 2; i <= n - 2; i++){
    tmp.clear();
    F(1, i);
    F(i + 1, n);
    sort(tmp.begin(), tmp.end());
    ans = min(ans, tmp[3] - tmp[0]);     
  }
  cout << ans << "\n";
  return 0;
}