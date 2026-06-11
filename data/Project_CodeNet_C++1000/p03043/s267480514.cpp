#include<bits/stdc++.h>
using namespace std;

#define io              ios_base::sync_with_stdio(false),cin.tie(NULL);
#define ll              long long
#define vi              vector<int>
#define pii             pair<int, int>
#define vii             vector<pii>
#define mii             map<int, int>

#define pb              push_back
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
#define c               1.00

int main()
{
    io;
    ll n,k;
    double ans = 0.0;
    cin >> n >> k;
    for(ll i = 1; i <= n; i++)
    {
        ll x = i;
        int steps = 0;
        while(x < k)
        {
            steps++;
            x *= 2;
        }
        ans += pow((1.00/2.00),steps);
    }
    ans /= (n*c);
    printf("%0.12f\n",ans);
}
