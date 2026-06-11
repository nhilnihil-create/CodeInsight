#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int a , b , c;

int main()
{
    _FastIO;
    cin >> a >> b >> c;
    c = min(c , b / a);
    cout << c << endl;
    return 0;
}
