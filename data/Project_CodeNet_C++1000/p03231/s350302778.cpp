#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int gcd(int X,int Y) {
    if(X%Y == 0) {
        return Y;
    }
    else {
        return gcd(Y,X%Y);
    }
}
signed main() {
    int N,M;
    cin >> N >> M;
    string S,T;
    cin >> S >> T;
    int X = gcd(N,M);
    for(int i = 0; i < X; i++) {
        if(S[N/X*i] != T[M/X*i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << N/X*M << endl;
}
