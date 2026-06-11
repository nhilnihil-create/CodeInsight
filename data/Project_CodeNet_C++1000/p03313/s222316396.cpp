#include<bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;
typedef pair < long long, long long > ii;

int a, n;

int b[maxn];

ii expon[maxn];
ii exponn[maxn];

long long res[maxn];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> a;

    n = (1<<a);

    for(int i=0;i<n;++i) cin >> b[i];

    for(int i=0;i<n;++i)
    {
        int tung = (1<<i);
        expon[i].first = b[i];
        expon[i].second = tung;
    }

	for(int i=0;i<a;++i)
    for(int j=0;j<n;++j)
    {
        int tung = (1<<i);
        if( (tung & j) )
        {
            int newval = tung ^ j;
            if( expon[j].first == expon[newval].first ) /// TH ==
            {
                if( exponn[j].first < expon[newval].first )
                if( expon[j].second != expon[newval].second )
                {
                    exponn[j] = expon[newval];
                    continue;
                }
            }

            if( expon[j].first < expon[newval].first ) /// TH <
            {
                exponn[j] = expon[j];
                expon[j] = expon[newval];
                continue;
            }
            if( exponn[j].first < expon[newval].first ) /// TH >
                exponn[j] = expon[newval];
        }
    }

    res[1] = max(expon[0].first + exponn[0].first, expon[1].first + exponn[1].first );
    for(int i=2;i<n;++i) res[i] = max(res[i-1], expon[i].first + exponn[i].first);

    for(int i=1;i<n;++i) cout << res[i] << '\n';

}


