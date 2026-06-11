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
    int ans;
    string s;

    cin >> s;

    int cnt0 = 0;
    int cnt1 = 0;
    rep(i, s.size()) {
        if (s[i] == '0')
            ++cnt0;
        else
            ++cnt1;
    }
    ans = min(cnt0, cnt1) * 2;
    cout << ans << endl;
    return(0);
}
