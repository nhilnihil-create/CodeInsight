#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 , -1};
signed main(){
    int A,B;
    cin >> A >> B;
    // 2 3 4 5 6 7
    if(A%2 == 0 && B%2 == 0) {
        int cnt = B-A;
        cnt/=2;
        if(cnt%2 == 0) {
            cout << B << endl;
        }
        else {
            int ans = 1;
            ans^=B;
            cout << ans << endl;
        }
    }
    // 2 3 4 5
    else if(A%2 == 0 && B%2 == 1) {
        int cnt = B-A+1;
        cnt/=2;
        if(cnt%2 == 0) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }
    // 3 4 5 6
    else if(A%2 == 1 && B%2 == 0) {
        int cnt = B-A-1;
        cnt/=2;
        if(cnt%2 == 0) {
            int ans = A^B;
            cout << ans << endl;
        }
        else {
            int ans = 1;
            ans^=A;
            ans^=B;
            cout << ans << endl;
        }
    }
    // 3 4 5 6 7
    else {
        int cnt = B-A;
        cnt/=2;
        if(cnt%2 == 0) {
            cout << A << endl;
        }
        else {
            int ans = 1;
            ans^=A;
            cout << ans << endl;
        }
    }
}
