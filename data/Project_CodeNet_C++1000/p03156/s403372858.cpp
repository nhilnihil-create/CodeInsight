#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define pb push_back

const int N = 1e2 + 10;

int n, limd, limu;
int p[N], cnt[3];

signed main()   {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> limd >> limu;
    FOR(i, 1, n)    {
        int x; cin >> x;
        if(x <= limd) cnt[0] ++;
        else if(x > limd && x <= limu) cnt[1] ++;
        else cnt[2] ++;
    }
    cout << min(cnt[0], min(cnt[1], cnt[2]));
}
