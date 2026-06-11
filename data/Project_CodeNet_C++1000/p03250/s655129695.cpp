#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int a[5];

int main()
{
    _FastIO;
    cin >> a[0] >> a[1] >> a[2];
    sort(a , a + 3);
    reverse(a , a + 3);
    cout << a[0] * 10 + a[1] + a[2] << endl;
    return 0;
}
