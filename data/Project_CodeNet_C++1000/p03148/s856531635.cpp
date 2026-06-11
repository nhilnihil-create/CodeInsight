#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
using ll = long long;
using ull = unsigned long long;

int main(void)
{
    IOS
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n,vector<int>());
    deque<int> su;      // 種類別1個目
    deque<int> deq;     // 2個目以降
    REP(i,n) {
        int t, d; cin >> t >> d;
        t--;
        v[t].emplace_back(d);
    }
    REP(i,n) sort(RALL(v[i]));
    
    ll d1 = 0;
    REP(i,n) {
        if (!v[i].empty()) {
            d1 += v[i].front();
            su.emplace_back(v[i].front());
            FOR(j,1,v[i].size()) deq.emplace_back(v[i][j]);
        }
    }

    sort(ALL(deq));
    sort(RALL(su));

    ll d2 = 0;
    ll kind = su.size();
    if ( kind > k ) {
        while (kind > k) {
            d1 -= su.back();
            kind--;
            su.pop_back();
        }
    } else if (kind < k) {
        FOR(i,kind,k) {
            d2 += deq.back();
            deq.pop_back();
        }
    }

    ll ans = kind * kind + d1 + d2;
    while(!deq.empty()) {
        ll tmp = (kind-1) * (kind-1) + d1 + d2 - su.back() + deq.back();
        if (ans < tmp) {
            kind--;
            d1 -= su.back();
            su.pop_back();
            d2 += deq.back();
            deq.pop_back();
            ans = tmp;
        } else break;
    }
    //cerr << kind << " " << d1 << " " << d2 << endl;
    cout << ans << endl;

    return 0;
}
