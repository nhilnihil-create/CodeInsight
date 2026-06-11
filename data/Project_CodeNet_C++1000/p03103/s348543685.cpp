#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i,n,init) for(ll i=init;i<(n);i++)
#define ll long long

bool pairCompare(const pair<int, int> & f, const pair<int, int> & s)
{
    return f.first < s.first;
}

int main()
{
    int n, m;
    ll ans;
    cin >> n >> m;
    vector<pair<int,int>> mise(n);
    rep(i, n) {
        int a1, b1;
        cin >> a1 >> b1;
        mise[i].first = a1;
        mise[i].second = b1;
    }

    sort(mise.begin(), mise.end(), pairCompare);
    ans = 0;
    int mm = m;
    rep(i, n) {
        if (mise[i].second >= mm) {
            ans += (ll)mise[i].first * mm;
            break;
        }
        mm -= mise[i].second;
        ans += (ll)mise[i].first * mise[i].second;
    }

    cout << ans << endl;
    return 0;
}