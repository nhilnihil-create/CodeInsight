#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    double percent = 0.0;
    double N, K;
    cin >> N >> K;
    for (int64_t i=1; i<=N; i++) {
        int64_t count = 0;
        int64_t n = i;
        while (n < K) {
            n = n * 2;
            count += 1;
        }

        if (count == 0) {
            percent += 1 / N;
        } else {
            percent += ((1 / N) * pow(0.5, count));
        }
    }

    cout << setprecision(13) << percent << endl;
    return 0;
}