#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[105];
signed main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int X = i;
        for(int j = 2; j*j <= i; j++) {
            if(X%j == 0) {
                while(X%j == 0) {
                    X/=j;
                    cnt[j]++;
                }
            }
        }
        if(X != 1) {
            cnt[X]++;
        }
    }
    int cnt3 = 0,cnt5 = 0,cnt15 = 0,cnt25 = 0,cnt75 = 0;
    for(int i = 2; i <= 100; i++) {
        if(cnt[i] >= 2) {
            cnt3++;
        }
        if(cnt[i] >= 4) {
            cnt5++;
        }
        if(cnt[i] >= 14) {
            cnt15++;
        }
        if(cnt[i] >= 24) {
            cnt25++;
        }
        if(cnt[i] >= 74) {
            cnt75++;
        }
    }
    cout << cnt75+cnt25*(cnt3-1)+cnt15*(cnt5-1)+cnt5*(cnt5-1)/2*(cnt3-2) << endl;
}
