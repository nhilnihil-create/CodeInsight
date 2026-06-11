#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int D,N;
    cin >> D >> N;
    int cnt = 0;
    for(int i = 1; i <= 10000000; i++) {
        int res = 0;
        int X = i;
        while (X%100 == 0) {
            res++;
            X/=100;
        }
        if(res == D) {
            cnt++;
        }
        if(cnt == N) {
            cout << i << endl;
            return 0;
        }
    }
}
