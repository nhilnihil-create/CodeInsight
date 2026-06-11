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
    ll n,k; cin >> n >> k;
    vector<ll> x(n);rep(i,n)cin >> x[i];
    ll mn = LINF;
    for (ll i = 0; i+k-1 <= n-1; i++)
    {
        ll r,l;
        l = x[i];r = x[i+k-1];
        if(0<=r && 0<=l)
        {
            mn = min(abs(r), mn);
        }else if (l<0 && 0<=r)
        {
            mn = min(2*abs(l)+abs(r),mn);
            mn = min(2*abs(r)+abs(l),mn);
        }else
        {
            mn = min(abs(l),mn);
        } 
        // cout << mn << endl;
    }
    cout << mn << endl;
    

}