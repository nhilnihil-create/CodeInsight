#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())
#define maxIndex(v) max_element(v.begin(), v.end()) - v.begin()
#define maxElement(v) *max_element(v.begin(), v.end())
#define minIndex(v) min_element(v.begin(), v.end()) - v.begin()
#define minElement(v) *min_element(v.begin(), v.end())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
using namespace std;

int main()
{
  ll N; cin >> N;
  vector<ll> C(N - 1), S(N - 1), F(N - 1);
  rep(i, 0, N - 1) {
  	cin >> C[i] >> S[i] >> F[i];
  }
  rep(i, 0, N - 1) {
  	ll T = S[i] + C[i];
    rep (j, i + 1, N - 1) {
      	if (T < S[j]) T = S[j];
   		ll b = (T - S[j]) % F[j];
   		if (b != 0) {
			T += F[j] - b;
        }
      	T += C[j];
    }
    cout << T << endl;
  }
  cout << 0 << endl;
}