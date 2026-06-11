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
    double n,m,d;cin >> n >> m >> d;
    double ans = 0;
    if(d!=0)
    {
        ans += (double)(m-1)*((double)2 * (double)(n - d) / (double)(n * n));
    }else
    {
        ans += (m-1)/n;
    }
    cout << setprecision(11) <<  ans << endl;
}