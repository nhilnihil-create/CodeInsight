#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<pair<ll, ll>>())
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
  ll N, H, a_max = 0, atk = 0; cin >> N >> H;
  vector<pair<ll, ll>> sword(N);
  rep(i, 0, N) {
  	ll a, b; cin >> a >> b;
    sword[i] = make_pair(b, a);
    if (a_max < a) a_max = a;
  }
  rvsort(sword);
  rep(i, 0, N) {
  	if (sword[i].first > a_max) {
    	H -= sword[i].first;
      	atk++;
      	if (H <= 0) {
        	cout << atk << endl;
          return 0;
        }
    }
  }
  atk += H / a_max;
  if (H % a_max) atk++;
  cout << atk << endl;
}