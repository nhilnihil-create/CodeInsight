#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll N, A, B, C, D, E;
    cin >> N >> A >> B >> C >> D >> E;
    vector<ll> cap(5);
    cap[0] = A, cap[1] = B, cap[2] = C, cap[3] = D, cap[4] = E;
    ll mn = pow(10, 16);
    int mn_itr = 0;
    rep(i, 5){
        if(mn > cap[i]){
            mn = cap[i];
            mn_itr = i;
        }
    }
    ll ans = 4;
    ans += (N + cap[mn_itr] - 1) / cap[mn_itr];
    cout << ans << endl;
    return 0;
}