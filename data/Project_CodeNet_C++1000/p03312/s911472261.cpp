#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 2e5+10;
const ll INF = (1ll<<60);

int N;
ll A[MAX];

int main() {

  cin >> N;

  ll sum = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    sum += a;
    A[i] = sum;
  }

  ll ans = INF;
  int l = 0;
  int c = 1;
  int r = 2;
  for (; c < N-2; c++) {
    while (true) {
      if (abs(A[c]-2*A[l]) < abs(A[c]-2*A[l+1])) break;
      l++;
      if (c-l == 1) break;
    }
    while (true) {
      if (abs(sum-2*A[r]+A[c]) < abs(sum-2*A[r+1]+A[c])) break;
      r++;
      if (N-r == 1) break;
    }
    vector<ll> v;
    v.push_back(A[l]);
    v.push_back(A[c]-A[l]);
    v.push_back(A[r]-A[c]);
    v.push_back(sum-A[r]);
    sort(v.begin(), v.end());
    ans = min(ans, v[3]-v[0]);
  }

  cout << ans << endl;
}