#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

ll r , d , x;

int main()
{
    _FastIO;
    cin >> r >> d >> x;
    for(ll i = 0; i < 10; i++){
        x *= r;
        x -= d;
        cout << x << endl;
    }
    return 0;
}
