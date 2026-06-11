#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int s,ss,cnt=1;
    cin >> s;
    ss = s;
    map<int,int>mp;
    mp[s]++;
    while (1) {
        cnt++;
        ss = (ss % 2 == 0) ? ss / 2 : 3 * ss + 1;
        if (!mp[ss])mp[ss]++;
        else break;
    }
    cout << cnt << endl;
    return 0;
}