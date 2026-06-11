#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
using namespace std;

int n,x,y;
string ans[] = { "Borys" , "Alice" };

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x >> y;
    cout << ans[ (y-x-1)%2 ];

    return 0;
}
