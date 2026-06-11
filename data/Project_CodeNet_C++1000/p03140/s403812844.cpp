#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)


int main(){
    ll n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    REP(i, n){
        char ai = a.at(i), bi = b.at(i), ci = c.at(i);
        if(ai != bi && bi != ci && ai != ci){
            ans += 2;
        }else if((ai != bi && bi == ci) || (ai == bi && bi != ci) || (ai == ci && ai != bi)){
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
