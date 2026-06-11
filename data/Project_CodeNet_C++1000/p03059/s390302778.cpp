#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int a , b , t;

int main()
{
    _FastIO;
    cin >> a >> b >> t;
    int ans = int(t / a) * b;
    cout << ans << endl;
    return 0;
}
