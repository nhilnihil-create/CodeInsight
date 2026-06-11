#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    cout << 0 << endl;
    string S;
    cin >> S;
    if(S == "Vacant") {
        return 0;
    }
    int l = 0,r = N;
    while(true) {
        int mid = (l+r)/2;
        cout << mid << endl;
        string T;
        cin >> T;
        if(T == "Vacant") {
            return 0;
        }
        if(mid%2 == 0) {
            if(S == T) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        else {
            if(S != T) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
    }
}
