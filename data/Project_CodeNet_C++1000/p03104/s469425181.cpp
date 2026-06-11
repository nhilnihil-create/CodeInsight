#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;

#define MOD 1000000007
#define PI 3.1415926535897932
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<int, int>
#define fi first
#define se second

typedef long long ll;

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

void solve1()
{
    ll a, b; cin >> a >> b;
    a--;
    ll ans = 0;
    ll div = 2;
    while(1) {
        ll bitnum1 = b/div*div/2;
        bitnum1 = b%div >= div/2? bitnum1 + b%div - div/2 + 1:bitnum1;

        ll bitnum2 = a / div*div/2;
        bitnum2 = a % div >= div / 2 ? bitnum2 + a % div - div / 2 + 1: bitnum2;

        if(bitnum1 >= 0 && bitnum2 >= 0) {
            if((bitnum1 - bitnum2)%2) {
                ans += div/2;
            }
        }

    

      
        if(2*b < div) {
            break;
        }

        div *= 2;
    }

    cout << ans << endl;

}

//11 = 11//2*1 + 11mod1 + 1
//12 = 12//8*4 + 12mod4 + 1

int main()
{
    solve1();
}
