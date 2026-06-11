#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
//#define int long long
//template<typename T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return true; } return false; }

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    double sum = 0;
    for (auto &a : A) { 
        cin >> a;
        sum += a;
    }
    sum = (double)sum/N;
    double d = 10000;
    int ans = -1;
    for (int i = 0; i < N; i++) {
        double m = (double)sum-A[i];
        if (m<0)m*=-1;
        if (chmin(d, m)) ans = i;
    }
    cout << ans << endl;
    return 0;
}