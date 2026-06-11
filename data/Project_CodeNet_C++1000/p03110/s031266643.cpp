#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

ll n;
long double ans , x;
string s;

int main()
{
    _FastIO;
    cout.precision(10);
    cin >> n;
    while(n--){
        cin >> x >> s;
        if(s == "JPY"){
            ans += x;
        }
        else{
            ans += (380000.0 * x);
        }
    }
    cout << fixed << ans << endl;
    return 0;
}
