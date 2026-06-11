#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template <class Iit>
void vout(const Iit &begin,const Iit &end,ostream &out) {
    for(auto it = begin; it != end; it++) {
        auto tmp = it;
        if (++tmp == end) out << *it << '\n';
        else out << *it << " ";
    }
}

int main(void)
{
    IOS
    int h, w;
    cin >> h >> w;
    vector<vector<int>> ss(h,vector<int>(w));
    REP(y,h) REP(x,w) cin >> ss[y][x];

    pii now{0,0},prev;

    auto move = [&](pii yx) {

        if (yx.first % 2 == 0) {
            if (yx.second == w-1) {
                // Down
                if (yx.first != h-1) yx.first++;
                return yx;
            } else {
                //right
                yx.second++;
                return yx;
            }
        } else {
            if (yx.second == 0) {
                // Down
                if (yx.first != h-1) yx.first++;
                return yx;
            } else {
                //left
                yx.second--;
                return yx;
            }
        }
    };

    vector<vector<int>> ans;
    bool odd = false;
    auto addans = [&](pii yx1,pii yx2) {ans.push_back({yx1.first+1,yx1.second+1,yx2.first+1,yx2.second+1});return;};

    do {
        if (odd) addans(prev,now);
        if (ss[now.first][now.second] % 2 != 0 ) odd = !odd;
        prev = now;
        now = move(now);
    } while (now != prev);

    OUT(ans.size());
    REP(i,ans.size()) vout(ALL(ans[i]),cout);

    return 0;
}