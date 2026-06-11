#include <bits/stdc++.h>
#include <cstdio>
#define fastio {ios_base::sync_with_stdio(false); cin.tie(NULL);}
#define nln cout << '\n'
#define ll long long int
#define INF (ll)1e+12
#define MAX 300100
#define mp(i, j) make_pair(i, j)
#define here cout  << "here";nln;
#define mul(a, b, mod) (((a % mod) * (b % mod)) % mod)
#define add(a, b, mod) (((a % mod) + (b % mod)) % mod)
#define inf 100000
#define M 1000000000LL

using namespace std;

ll a[200100];

int main()
{
    ll n, l, k, i, ans, cnt, x;

    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> x;
        a[x] = i;
    }

    cnt = 1;
    ans = n;
    for(i = 2; i <= n ; i++){
        if(a[i] < a[i-1]){
           ans = min(n-cnt, ans);
           cnt = 0;
        }
        cnt++;
    }

    ans = min(n-cnt, ans);

    cout << ans << endl;
}
