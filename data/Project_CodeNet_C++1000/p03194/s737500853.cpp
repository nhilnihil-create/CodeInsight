#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    ll N, P;
    cin >> N >> P;

    ll pp = P;
    map<ll, ll> ma;
    for(ll i = 2; i*i <= P; i++){
        while(P%i == 0){
            ma[i]++;
            P /= i;
        }
    }
    if(P != 1) ma[P]++;

    ll ans = 1;
    for(pair<ll, ll> p : ma){
        ll x = p.first;
        ll y = p.second;
        //printf("%d, %d\n", x, y);
        ll num = y/N;
        if(num > 0) ans *= pow(x, num);
    }
    //for(int i = 2; i*i < pp; i++){
    //    printf("%d\n", i);
    //    if(ma.find(i) == ma.end()) continue;
    //    int num = ma[i]/N;
    //    if(num > 0) ans *= pow(i, num);
    //}

    cout << ans << endl;
    return 0;
}
