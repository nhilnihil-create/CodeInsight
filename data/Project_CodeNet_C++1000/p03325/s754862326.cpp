#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , x;

int main()
{
    _FastIO;
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        while(x % 2 == 0){
            x /= 2;
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}
