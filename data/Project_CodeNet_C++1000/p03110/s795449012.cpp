#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N;
    cin >> N;
    double sum = 0;
    rep(i,N) {
        double m;
        string s;
        cin >> m >> s;
        if (s == "JPY") {
            sum += m;
        } else {
            sum += m * 380000.0;
        }
    }
    cout << fixed << setprecision(12);
    cout << sum << endl;
}
