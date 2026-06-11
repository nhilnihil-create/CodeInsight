#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    int now = 0;
    for(int i = N-1; i >= 1; i--) {
        if(A[i] > A[i-1]+1) {
            cout << -1 << endl;
            return 0;
        }
        if(now != A[i]) {
            ans += A[i];
            if(i < A[i]) {
                cout << -1 << endl;
                return 0;
            }
            now = A[i]-1;
        }
        else {
            now--;
        }
    }
    if(A[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}