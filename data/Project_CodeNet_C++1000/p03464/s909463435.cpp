// be name khoda
#include<bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
//#define mp make_pair 
typedef long long ll;
#define int long long
#pragma GCC optimize("Ofast")
 
const int maxn = 1e5+10;
const int mod = 1e9+7;
const ll inf = 1e18+10;
//const int N = 2e6+10;
 
int n, k;
int a[maxn];

int ok(int n)
{
    for(int i = 1; i <= k; i++)
        n = n - n % a[i];
    if(n == 2) return 1;
    if(n > 2) return 2;
    if(n < 2) return 0;
}

signed main()
{
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>> k;
    for(int i = 1; i <= k; i++) cin>> a[i];

    int lo = -1, hi = inf;
    while (hi-lo > 1)
    {
        int tm = (hi+lo) >> 1;
        if(ok(tm) >= 1) hi = tm;
        else lo = tm;
    }
    int X = hi;

    lo = -1, hi = inf;
    while (hi-lo > 1)
    {
        int tm = (hi+lo) >> 1;
        if(ok(tm) > 1) hi = tm;
        else lo = tm;
    }
    int Y = lo;

    if(X > Y) cout<< -1;
    else cout<< X <<" "<< Y;
}
