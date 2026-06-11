#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int A,B,C,K;
    cin >> A >> B >> C >> K;
    if(K%2 == 0) {
        cout << A-B << endl;
    }
    else {
        cout << B-A << endl;
    }
}
