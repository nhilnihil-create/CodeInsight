#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    int ans = 1;
    int cnt = 1;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        ans*=3;
        if(A%2 == 0) {
            cnt*=2;
        }
    }
    cout << ans-cnt << endl;
}