#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define INF 100000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
int main(){
    string S;
    cin >> S;
    ll ans = 0,cnt[200007];
    bool fin = false;

    rep(i,S.length()) cnt[i] = 0;
    rep(i,S.length()){
        if(S[i] == 'B'){
            cnt[i+1] = cnt[i] + 1;
        }else cnt[i + 1] = cnt[i];
        if (S[i] == 'W') ans += cnt[i];
    }
    cout << ans << endl;
    return 0;
}