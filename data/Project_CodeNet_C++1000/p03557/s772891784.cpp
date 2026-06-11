#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    ll i;
    for(i = 0; i < n; i++){
        ll inp;
        cin >> inp;
        a.at(i) = inp;
    }
    for(i = 0; i < n; i++){
        ll inp;
        cin >> inp;
        b.at(i) = inp;
    }
    for(i = 0; i < n; i++){
        ll inp;
        cin >> inp;
        c.at(i) = inp;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll count = 0;
    for(i = 0; i < n; i++){
        ll b0 = b.at(i);
        auto ita = lower_bound(a.begin(), a.end(), b0) - 1;
        auto itc = upper_bound(c.begin(), c.end(), b0);
        ll na = ita - a.begin();
        ll nc = c.end() - itc;
        if(*ita < b0 && b0 < *itc) count += (na + 1) * (nc);
    }
    cout << count << endl;
  	return 0;
}
