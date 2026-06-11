#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)

typedef long long ll;

signed main()
{
    int R,G,B,N; cin >> R >> G >> B >> N;

    ll ans = 0;
    for (int r = 0; r*R <= N; ++r){
        int remain = N - r*R;
        for (int g = 0; g*G <= N; ++g){
            int remain2 = remain - g*G;
            if (remain2 < 0) continue;
            if (remain2 % B == 0) ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
