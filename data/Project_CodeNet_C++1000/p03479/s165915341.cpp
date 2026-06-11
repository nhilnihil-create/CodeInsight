#include <bits/stdc++.h>
#define INF 1e7

using namespace std;
typedef long long int ll;
typedef tuple<int,int,int> tii;
typedef tuple<long long int,long long int,long long int> tll;

int main()
{
    ll x,y; cin >> x >> y;
    ll a = x;
    int ans = 1;
    while(1)
    {
        ll b = 2*a;
        if(b > y) break;
        a = b;
        ans++;
    }
    cout << ans << endl;
}