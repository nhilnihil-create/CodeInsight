#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

// bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
//     return arg1.first > arg2.first;
// }

int main(void) {
    int x, y, z, k;
    cin >> x >> y >> z >> k;

    vector<ll> a(x);
    vector<ll> b(y);
    vector<ll> c(z);
    for(int ix=0;ix<x;ix++) {
        cin >> a.at(ix);
    }
    for(int iy=0;iy<y;iy++) {
        cin >> b.at(iy);
    }
    for(int iz=0;iz<z;iz++) {
        cin >> c.at(iz);
    }

    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());

    vector<ll> ans;
    for(int ix=0;ix<x;ix++) {
        for(int iy=0;iy<y;iy++) {
            for(int iz=0;iz<z;iz++) {
                if((ix+1)*(iy+1)*(iz+1)<=3000) ans.push_back((ll)a.at(ix)+(ll)b.at(iy)+(ll)c.at(iz));
            }
        }
    }

    sort(ans.begin(), ans.end(), greater<ll>());

    for(int ik=0;ik<k;ik++) {
        cout << ans.at(ik) << endl;
    }

    return 0;
}
