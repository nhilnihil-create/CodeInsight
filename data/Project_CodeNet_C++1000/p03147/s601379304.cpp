#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i,n,init) for(ll i=init;i<(n);i++)
#define ll long long

int main()
{
    int n,m,ans;

    cin >> n;
    vector<int> h(n);
    rep(i, n) {
        cin >> h[i];
    }

    ans = 0;
    int i = 0;
    do {
        if (h[i] == 0) {
            ++i;
            continue;
        }

        for (int j = i;j < n;++j) {
            if (h[j] == 0)
                break;
            --h[j];
        }
        ++ans;

    } while (i < n);

    cout << ans << endl;
    return(0);
}
