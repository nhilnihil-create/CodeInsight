#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <deque>

using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
#define OUT(n) cout << (n) << endl;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
 
constexpr bool ygreater(const pii &a, const pii &b) {
    return a.second < b.second;
}
 
int main(void)
{
    //IOS
    int n; cin >> n;
    vector<pii> r,b;
    REP(i,n) {
        int x, y;
        cin >> x >> y;
        r.push_back({x,y});
    }
    REP(i,n) {
        int x, y;
        cin >> x >> y;
        b.push_back({x,y});
    }
    sort(ALL(r));
    sort(ALL(b));
    int ans = 0;
    vector<bool> ruse(r.size());
 
    REP(i,n) {
        int maxry = -1;
        int maxryj = -1;
        REP(j,n) {
            if (b[i].first > r[j].first && b[i].second > r[j].second && !ruse[j]) {
                if (maxry < r[j].second) {
                    maxry = r[j].second;
                    maxryj = j;
                }
            }
        }
        if (maxryj != -1) {
            cerr << r[i].first << " " << r[i].second << " " <<b[maxryj].first << " " <<b[maxryj].second <<endl; 
            ruse[maxryj] = true;
            ans++;
        }
    }

    cout << ans << endl;
 
    return 0;
}