#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N, K;
    cin >> N >> K;
    int X = ceil(log2(K));
    double ans = 0;

    for(int i=1; i<=N; i++) {
        if(i >= K) {
            ans += (1.0/N);
            continue;
        }
        int n = ceil(log2(K)-log2(i));
        ans += (double)pow(0.5, n)/N;
    }
    cout << fixed << setprecision(12) << ans << endl;
}