#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;


int main(void)
{
    IOS
    int n;
    cin >> n;
    vector<int> v(n);
    map<int,int> mp;
    REP(i,n) {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(RALL(v));
    ll ans = 0;

    REP(i,n) {
        if (mp[v[i]] <= 0) continue; 
        double l2 = log2(v[i]);
        if (l2 == floor(l2)) {
            //cerr << "p" << endl;
            if (mp[v[i]] >= 2) {
                ans++;
                mp[v[i]]--;
            }
        } else {
            l2 = ceil(l2);
            int p = pow(2,l2);
            if (mp[p-v[i]] > 0) {
                //cerr << v[i] <<" "<< p << " " <<p-v[i]<<" "<< mp[p-v[i]] << endl;
                ans++;
                mp[p-v[i]]--;
            }
        }
        mp[v[i]]--;
    }


    cout << ans << '\n';

    return 0;
}