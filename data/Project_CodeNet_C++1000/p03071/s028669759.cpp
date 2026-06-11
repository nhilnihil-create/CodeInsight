#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int a , b;

int main()
{
    _FastIO;
    cin >> a >> b;
    if(a < b) swap(a , b);
    int ans = max((2 * a) - 1 , (a + b));
    cout << ans << endl;
    return 0;
}
