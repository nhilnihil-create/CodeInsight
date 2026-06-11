#include <bits/stdc++.h>

using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define M 1000000007
#define vvi vector<vector<int>>
//#define FILE_A_IN

void solve() {
    int n;
    cin >> n;
    vector<int> in(n);
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    sort(in.begin(), in.end());
    for (int i = in[1]; i >= 1; --i) {
        int c = 0;
        for (int j = 0; j < n; ++j) {
            if(in[j] % i != 0) ++c;
            if(c > 1 ) break;
        }
        if( c  <= 1) {
            cout << i << endl;
            return;
        }
    }
    cout << 1 << endl;
}
int main() {
#ifdef FILE_A_IN
    freopen("a.in", "r", stdin);
#endif
    fio;
        solve();
    return 0;
}