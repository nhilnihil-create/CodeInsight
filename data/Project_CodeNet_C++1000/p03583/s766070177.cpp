#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){
    ll N; cin >> N;
    if (N % 2 == 0)
        cout << N << " " << N << " " << (N / 2) << endl;
    else{
        for (int h = 1; h <= 3500; ++h){
            for (int n = 1; n <= 3500; ++n){
                ll den = N * h * n;
                ll num = 4 * h * n - N * (h + n);
                if (num <= 0) continue;
                if (den % num) continue;
                cout << h << " " << n << " " << (den / num) << endl;
                return 0;
            }
        }
    }
    return 0;
}