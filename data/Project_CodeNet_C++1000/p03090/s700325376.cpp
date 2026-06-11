#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    cout << N*(N-1)/2-N/2 << endl;
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            if(i+j == N && N%2 == 1) {
                continue;
            }
            if(i+j == N+1 && N%2 == 0) {
                continue;
            }
            cout << i << " " << j << endl;
        }
    }
}
