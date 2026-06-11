#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e14;
const int ZERO = 0;
const int MOD = 1000000007;
const double PI = 3.1415926535897;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0;i < N;i++) {
        cin >> A.at(i);
    }
    if(A.at(0) != 0) {
        cout << -1 << endl;
    }
    else {
        for(int i = 0;i < N - 1;i++) {
            if(A.at(i + 1) >= A.at(i) + 2) {
                cout << -1 << endl;
                return 0;
            }
        }
        reverse(A.begin(),A.end());
        int ret = 0;
        int cnt = A.at(0);
        int cnt2 = 1;
        for(int i = 1;i < N;i++) {
            if(A.at(i) != cnt - cnt2) {
                ret += cnt;
                cnt = A.at(i);
                cnt2 = 1;
            }
            else {
                cnt2++;
            }
        }
        ret += cnt;
        cout << ret << endl;
    }
}