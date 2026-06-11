#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,A;
    cin >> N >> A;
    if(N%500 <= A) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
