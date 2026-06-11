#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long
#define rep(cnt,a,n) for(ll cnt=a;cnt<n+a;cnt++) //aから始めてn回ループ


int main()
{
    ll n;
    cin >> n;
    ll time;
    cin >> time;

    vector<ll> c(n);
    vector<ll> t(n);

    rep(cnt,0,n) {

        cin >> c[cnt];
        cin >> t[cnt];
    }

    ll min=3000;

    rep(cnt, 0, n) {
        if (t[cnt] <= time) {
            if (c[cnt] < min) {
                min = c[cnt];
            }
        }

    }
    if (min > 1000) {
        cout << "TLE" << endl;
    }
    else {
        cout << min << endl;
    }
 


    return 0;
}