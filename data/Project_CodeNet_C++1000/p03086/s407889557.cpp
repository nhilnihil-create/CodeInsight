//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    string s;
    cin >> s;
    int ans = 0;
    int tmp = 0;
    for(auto v : s) {
        if(v == 'A' || v == 'C' || v == 'G' || v == 'T') {
            tmp++;
            ans = max(ans, tmp);
        }else {
            tmp = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
