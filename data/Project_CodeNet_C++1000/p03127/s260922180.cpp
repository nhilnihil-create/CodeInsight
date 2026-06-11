#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;

int main() { 
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++)cin >> A[i];
    while (true) {
      ll cnt0 = 0;
      ll mini = INF;
      ll idx = -1;
      sort(A.begin(), A.end());
      for(int i = 0; i < N; i++){
        if (A[i] != 0) {
            mini = A[i];
            idx = i;
            break;
        }
        else cnt0++;
      }
      if (cnt0 == N-1) break;
      for (int i = cnt0; i < N; i++) {
        if (i == idx) continue;
        A[i] = A[i] % mini;
      }
    }

    cout << A[N-1] << endl;
    return 0;
}