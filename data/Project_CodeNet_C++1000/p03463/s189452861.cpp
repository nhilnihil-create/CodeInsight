#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define inf 1e18
#define pi acos(-1.0)
#define mod 998244353

int main(void)
{
    fastio;

    int n,a,b;
    cin >> n >> a >> b;

    if(n==2)cout << "Borys";
    else if((b-a-1)%2)cout << "Alice";
    else cout << "Borys";

    return 0;
}
