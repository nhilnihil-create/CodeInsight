#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    int cnt = 0;
    vector<int>a(N);
    vector<int>b(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) cin >> b[i];
    for(int i = 0; i < N; i++) {
        if(a[i] > b[i]) {
            cnt-=a[i]-b[i];
        }
        else {
            cnt+=(b[i]-a[i]+1)/2-(b[i]-a[i])%2;
        }
    }
    if(cnt < 0) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}
