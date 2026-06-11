#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int K,A,B;
    cin >> K >> A >> B;
    if(A > B) {
        cout << K+1 << endl;
    }
    else {
        if(A+2 >= B) {
            cout << K+1 << endl;
        }
        else {
            K-=A-1;
            cout << K/2*(B-A)+K%2+A <<endl;
        }
    }
}
