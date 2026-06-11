#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    double N,K;
    cin >> N >> K;
    double cnt = 0;
    for(double i = 1; i <= N; i++) {
        double res = 1;
        double X = i;
        while(X < K) {
            X*=2;
            res/=2;
        }
        cnt+=res;
    }
    cout << fixed << setprecision(20) << cnt/N << endl;
}