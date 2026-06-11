#include <bits/stdc++.h>
#define ll long long
#define fort(i,n) for (int i = 1; i <= n; ++i)
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define sz size()
#define er erase
#define fr first
#define sc second
#define rc(x) return cout << x, 0
using namespace std;



int32_t main()
{
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    int n,a,b;
    cin >> n >> a >> b;
    cout << min(a,b) << ' ' << max(0,a+b-n);
}
