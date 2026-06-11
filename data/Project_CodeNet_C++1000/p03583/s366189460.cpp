#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
    return arg1.first > arg2.first;
}

int main(void) {
    ll n;
    cin >> n;

    ll l, r;
    for(ll ih=1;ih<=3500;ih++) {
        for(ll in=1;in<=3500;in++) {
            l = n*ih*in;
            r = 4*ih*in-n*(ih+in);
            if(r==0) continue;
            if(l%r==0&&r>0) {
                cout << ih << " " << in << " " << l/r << endl;
                return 0;
            }
        }
    }

    return 0;
}
