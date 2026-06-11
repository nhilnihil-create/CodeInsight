#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> h(N);
  for(int i = 0; i < N; i++) {
    cin >> h[i];
  }

 int ans = 0;
  while (*max_element(h.begin(), h.end()) != 0) {
    for (int i = 0; i < N; i++) {
      if(h[i] != 0)  {
        ans++;
        while (i < N && h[i] > 0) {
          h[i]--;
          i++;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
