#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
/****************************************************************************************************************************************************/

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MOD 1000000007
/********************************************************************************************************************************************************/


const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
/*********************************************************************************************************************************************************/
const ll mx=1e5+3;
ll k,n,w[mx];
ll dp[mx];
ll ks(ll i)
{
    if(i>=n)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    ll c=INT_MAX;
    for(int j=1; j<=k; j++)
    {
        if(i+j<=n)
            c=min(c,abs(w[i]-w[i+j])+ks(i+j));
    }
    return dp[i]=c;
}

int main()
{
    optimize();
    for(int i=0; i<mx; i++)
    {
        dp[i]=-1;
    }
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        cin>>w[i];
    cout<<ks(1)<<endl;

    return 0;
}




