#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int a , b , x;

int main()
{
    _FastIO;
    cin >> a >> b >> x;
    if(x >= a && x <= (a + b)){
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
