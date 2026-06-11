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
    int n; cin >> n;
    vector<ll> v(n);
    ll mn = 1LL << 60;
    ll mx = (1LL << 60) * -1;
    int mni,mxi;

    auto ifmax = [&](int i) {
            if (mx < v[i]) {
            mx = v[i];
            mxi = i;
            }
        };
    auto ifmin = [&](int i) {
            if (mn > v[i]) {
                mn = v[i];
                mni = i;
            }
        };

    REP(i,n) {
        cin >> v[i];
        ifmax(i);
        ifmin(i);
    }

    vector<pair<int,int>> p;
    
    if (mx < 0 || (abs(mx) < abs(mn))) {
        for (auto i = n-1; i >= 0 ; i--) {
            p.emplace_back(make_pair(mni+1,i+1));
        }
        for (auto i = n-1; i > 0 ; i--) {
            p.emplace_back(make_pair(i+1,i));
        }
    } else {
        for (auto i = 0; i < n ; i++) {
            p.emplace_back(make_pair(mxi+1,i+1));
        }
        for (auto i = 0; i < n-1 ; i++) {
            p.emplace_back(make_pair(i+1,i+2));
        }
    }

    cout << p.size() << endl;
    for(auto x:p) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}