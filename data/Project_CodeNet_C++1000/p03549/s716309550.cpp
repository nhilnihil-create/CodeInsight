#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    double sm = 0.0, p = (1 << M);
    p = 1/p;
    int x = 1900*M + 100*(N - M);
    
    sm = x/p;
    int ans = (int)sm;
    cout << ans << "\n";
    return 0;
}
