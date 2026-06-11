#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
long long C;
long long a[N];
long long b[N];
long long s[N];
long long suf[N];
long long pref[N];

void solve()
{
        cin >> n >> C;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i];
                s[i] = s[i - 1] + b[i];
        }
        for(int i = n; i >= 1; i--){
                suf[i] = suf[i + 1];
                suf[i] = max(suf[i], s[n] - s[i - 1] - C + a[i]);
        }
        for(int i = 1; i <= n; i++){
                pref[i] = pref[i - 1];
                pref[i] = max(pref[i], s[i] - a[i]);
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
                ans = max(ans, s[i] - a[i]);
                ans = max(ans, s[n] - s[i - 1] - C + a[i]);
                ans = max(ans, s[i] - 2 * a[i] + suf[i + 1]);
                ans = max(ans, s[n] - s[i - 1] - 2 * C + 2 * a[i] + pref[i - 1]);
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}
