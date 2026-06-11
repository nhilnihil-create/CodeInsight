#include <bits/stdc++.h>
using namespace std;





















vector<long long> divisor_array (long long N) {
    vector<long long> a;
    for (long long i = 1; i * i <= N; i++) {
        if (i * i == N) {
            a.push_back(i);
        }
        else if (N % i == 0) {
            a.push_back(i), a.push_back(N / i);
        }
    }
    return a;
}






 int main () {
    int N, M;
    cin >> N >> M;

    /* for (int i = N; ; i++) {
        if (M % i == 0) {
            cout << N / i << endl;
            break;
        }
    } */
    
    vector<long long> a = divisor_array(M);
    sort (a.begin(), a.end());

    auto dot = lower_bound(a.begin(), a.end(), N);
    long long result = *dot;
    cout << M / result << endl;
}