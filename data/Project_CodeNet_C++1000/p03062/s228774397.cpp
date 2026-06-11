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
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n;cin >> n;
    vector<ll> a(n);rep(i,n)cin >> a[i];
    int minus = 0;
    ll mn = INF;
    rep(i,n)
    {
        if(a[i]<0)
        {
            minus++;
        }
        chmin(mn, abs(a[i]));
    }
    ll sum = 0;
    rep(i, n)
    {
        sum += abs(a[i]);
    }
    if(minus%2==1)
    {
        sum -= 2*mn;
    }
    cout << sum << endl;
}