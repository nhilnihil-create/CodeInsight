#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,K;
    cin >> N >> K;
    string ans;
    ans = 2*K-1<=N ? "YES" : "NO";
    cout << ans << '\n';
    return 0;
}