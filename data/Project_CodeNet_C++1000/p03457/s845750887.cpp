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
    vector<int>t(N+1);
    vector<int>x(N+1);
    vector<int>y(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    for(int i = 1; i <= N; i++) {
        int X = abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
        if(t[i]-t[i-1] < X) {
            cout << "No" << endl;
            return 0;
        }
        if((t[i]-t[i-1])%2 != X%2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
