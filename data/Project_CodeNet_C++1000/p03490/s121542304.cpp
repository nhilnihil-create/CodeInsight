#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

const string YES = "Yes";
const string NO = "No";

const int OFF = 8005;

int dp[2][16010];

void solve(std::string s, long long x, long long y){
    vector<vector<int>> a(2);
    vector<int> b;
    b.push_back(x); b.push_back(y);
    int cnt = 0, p = 0;
    s += 'T';
    cerr << s << x << y << endl;
    for(int i = 0; i < s.size(); ++i) {
        if (s[i] == 'F') {
            ++cnt;
        } else {
            a[p].push_back(cnt);
            cnt = 0;
            p = 1 - p;
        }
    }
    cerr << "hog" << endl;

    for(int k = 0; k < 2; ++k) {
        memset(dp, 0, sizeof(dp));
        if (k == 0) {
            dp[0][a[k][0] + OFF] = 1;
        } else {
            dp[0][OFF + 0] = 1;
        }
        p = 0;
        int q = 1;
        for(int j = k == 0 ? 1: 0; j < a[k].size(); ++j) {
            for(int i = -8000; i <= 8000; ++i) {
                if (OFF + i - a[k][j] >= 0) {
                    dp[q][OFF + i] |= dp[p][OFF + i - a[k][j]];
                }
                if (OFF + i + a[k][j] < 2 * OFF) {
                    dp[q][OFF + i] |= dp[p][OFF + i + a[k][j]];
                }
            }
            memset(dp[p], 0, sizeof(int[16010]));
            swap(p, q);
        }
        if (!dp[p][b[k] + OFF]) {
            cout << NO << endl;
            return;
        }
    }
    cout << YES << endl;
}

char str[8010];
signed main(){
    ios::sync_with_stdio(false);
    scanf("%s", str);
    std::string s(str);
    // std::cin >> s;
    long long x;
    long long y;
    scanf("%lld", &x);
    scanf("%lld", &y);
    solve(s, x, y);
    return 0;
}
