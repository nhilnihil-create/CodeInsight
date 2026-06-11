#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int N, K;
   cin >> N >> K;
   
   vector<int> x(N);

   for(int i = 0; i < N; i++) {
       cin >> x[i];
   }
    ll res = 1000000000000000;
    for(int i = 0; i <= N - K; i++) {
        ll left = x[i];
        ll right = x[i + K - 1];

        res = min(res, right - left + min(abs(left), abs(right)));

    }

    cout << res << endl;
    return 0;

}