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
    int n,m;
    cin >> n >> m;
    if (n==1 && m==1)
    {
        cout << 1 << endl;
        return 0;
    }
    if(n==1)
    {
        cout << m-2 << endl;
        return 0;
    }
    if(m==1)
    {
        cout << n-2 << endl;
        return 0;
    }
    cout << (ll)(n - 2) * (ll)(m - 2) << endl;
    return 0;
}