#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

const int N = 10001, M = 9;
int n, m;
int a[M];
string dp[N];
bool done[N];
bool bad[N];

int msticks[] = {10000, 2, 5, 5, 4, 5, 6, 3, 7, 6};

string mymax(string& a, string& b) {
    int sza = a.length(), szb = b.length();
    if(sza > szb) return a;
    if(szb > sza) return b;
    if(a > b) return a;
    return b;
}

string solve(int rem) {
    if(done[rem]) return dp[rem];

    string ret = "";
    for(int i = 0; i < m; ++i) {
        int d = a[i], ms = msticks[d];
        if(rem - ms >= 0) {
            char c = d + '0';
            string cand = c + solve(rem - ms);
            if(bad[rem-ms]) continue;
            ret = mymax(ret, cand);
        }
    }
    done[rem] = true;
    if(ret.empty()) {
        bad[rem] = true;
    } else {
        dp[rem] = ret;
    }
    return ret;
}

int32_t main() {
    
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    done[0] = true;
    string ans = solve(n);

    cout << ans << endl;

    return 0;
}
