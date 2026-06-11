#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, h, w;
    cin >> n >> h >> w;
    ll count = 0;
    for(int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        if(h <= a && w <= b)
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
