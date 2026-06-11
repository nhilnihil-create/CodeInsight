#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////
int main(){
    ll x, D, r;
    cin >> r >> D >> x;
    rep(_,10){
        x = r * x - D;
        cout << x << endl;
    }
}
