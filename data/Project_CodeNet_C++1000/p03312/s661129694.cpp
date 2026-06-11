#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <complex>
#include <cctype>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <iomanip>
#include <limits.h>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cout << i << "\n"

const ll INF = 100000000;
const ll MOD = 1000000007;

ll pow_mod(ll a,ll b,ll mod){
    if(a%mod==0){
        return 0;
    }

    ll x = 1;

    while(b>0){
        if(b&1){
            x = (x * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return x;
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    //問題文中の添え字が0-indexか1-indexか確認!

    ll n, left = 0, right = 2, ans = INT_MAX;
    ll P=0, Q=0, R=0, S=0;
    std::cin >> n;
    std::vector<ll> a(n);
    rep(i,0,n){
        std::cin >> a[i];
        S += a[i];
    }
    Q = a[0]+a[1];
    S -= Q;
    rep(i, 2, n)
    {
        std::vector<ll> temp(4);
        //P,Qの処理
        while(P+a[left]<Q-a[left]){
            P += a[left];
            Q -= a[left];
            left++;
        }

        //debug(P << " "<<Q);

        if(Q-P<a[left]){
            temp[0] = Q;
            temp[1] = P;
        }else{
            temp[0] = Q - a[left];
            temp[1] = P + a[left];
        }

        Q += a[i];

        //R,Sの処理
        while(R+a[right]<S-a[right]){
            R += a[right];
            S -= a[right];
            right++;
        }

        //debug(R  << " "<<  S);

        if (S - R < a[right])
        {
            temp[2] = S;
            temp[3] = R;
        }
        else
        {
            temp[2] = S - a[right];
            temp[3] = R + a[right];
        }

        R -= a[i];

        //ansの更新
        std::sort(all(temp));
        //rep(i,0,4){
        //    debug("temp"<<temp[i]);
        //}
        ans = std::min(ans, temp[3] - temp[0]);
    }

    std::cout << ans;
    return 0;
}