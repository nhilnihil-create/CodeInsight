#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 50005

int main()
{
    _FastIO;

    int a , b;
    cin >> a >> b;
    int ans = 0;
    for(int i = a; i <= b; i++){
        int x = i / 10000;
        int y = (i / 1000) % 10;
        int r = (i / 10) % 10;
        int t = i % 10;
        if(x == t && y == r)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
