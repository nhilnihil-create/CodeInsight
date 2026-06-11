#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
        ll rr, cc; cin >> rr >> cc;
        ll r, c; cin >> r >> c;
        ll res = rr*cc - r*cc - c*rr + r*c; cout << res << endl;
    return 0;
}
