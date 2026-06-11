#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    if(k==0)
    {
        cout << n*n << endl;
        return 0;
    }
    for (int b = k+1; b < n+1; b++)
    {
        ll syou = n/b;
        ll amari = n%b;
        ll kosu = b-k;
        ll temp = syou*kosu;
        if((amari-k)>=0) temp+= amari-k+1;
        ans += temp;
    }
    cout << ans << endl;
}