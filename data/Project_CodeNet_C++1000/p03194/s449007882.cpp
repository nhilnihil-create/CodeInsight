#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (int i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,v) for (int i = 0; i < v.size(); i++)
#define SORT(v) sort(v.begin(), v.end())
#define MIN_ELEMENT(v) min_element(v.begin(), v.end())
#define MAX_ELEMENT(v) max_element(v.begin(), v.end())
#define COUNT(v,n) count(v.begin(), v.end(), n);
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e7;
const ll MOD = 1e9 + 7;



int main()
{
    ll n, p;
    cin>>n>>p;
/*
    vector<ll> prm;
    prm.push_back(2);

    ll imax = sqrt(p) + 1;
    for (ll i = 3; i < imax; i += 2) {
        int jmax = prm.size();
        bool flag = true;
        REP(j, jmax) {
            if (i % prm[j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            prm.push_back(i);
        }
    }

    REPALL(i,prm) cout<<prm[i]<<" ";

    vector<int> ele(prm.size());
    int jmax = prm.size();
    REP(j, jmax) {
        while (p % prm[j] == 0) {
            ele[j]++;
            p /= prm[j];
        }
    }

    ll ans = 1;
    REP(j, jmax) {
        REP(k,ele[j]/n){
            ans *= prm[j];
        }
    }

    cout<<ans<<endl;
*/

    ll ans = 1;
    if (n == 1) {
        ans = p;
    } else if (n > p) {
        ans = 1;
    } else if (n == p) {
        if (n == 2) ans = 2;
        else ans = 1;
    } else {
        for (ll i = 2; i * i <= p; i++) {
            //cout<<i<<endl;
            bool flag = true;
            ll tmp = 1;
            REP(j,n) {
                tmp *= i;
                if (tmp > p) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
            if (p % tmp == 0) {
                ans = i;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
