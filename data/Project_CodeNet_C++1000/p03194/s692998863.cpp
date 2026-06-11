#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
typedef long long ll;
ll const MOD = 1e9+7;
ll const INF = 1e18;
using namespace std;

int main(){
    ll n, p;
    cin >> n >> p;
    if(n == 1){
        cout << p << endl;
        return 0;
    }
    ll i = 2, ans = 1;
    while(i <= sqrt(p)){
        ll d = (ll)pow(i, n);
        while(p%d == 0){
            ans *= i;
            p /= d;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}