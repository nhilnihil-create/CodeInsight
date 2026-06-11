#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll findXORofRange(ll m, ll n)
{


    if(m % 2 == 0)
    {
        ll  patternTracker[]= {n, 1, n^1, 0};
        return patternTracker[(n-m) % 4];
    }
    else
    {
        ll patternTracker []= {m, m^n, m-1, (m-1)^n};
        return patternTracker[(n-m) % 4];
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll x,y;
    cin>>x>>y;

    cout<<findXORofRange(x,y)<<endl;


    return 0;
}
