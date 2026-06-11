#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int K;
    cin >> K;
    vector<int>A(K);
    for(int i = 0; i < K; i++) {
        cin >> A[i];
    }
    bool ok = false;
    int l = 1,r = INF;
    while (l+1 < r) {
        int mid = (l+r)/2;
        int X = mid;
        for(int i = 0; i < K; i++) {
            X-=X%A[i];
        }
        if(X == 2) {
            ok = true;
        }
        if(X >= 2) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    if(!ok) {
        cout << -1 << endl;
        return 0;
    }
    cout << l+1 << " ";
    l = 1;r = INF;
    while (l+1 < r) {
        int mid = (l+r)/2;
        int X = mid;
        for(int i = 0; i < K; i++) {
            X-=X%A[i];
        }
        if(X > 2) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r-1 << endl;
}