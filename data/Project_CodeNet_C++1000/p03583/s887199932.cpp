#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
    ll N; cin >> N;
    ll h, n, w;
    ll N_ch = 1;
    ll N_mo = N;
    for(ll i = 1; i <= 3500; i++){ // h
        for(ll j = 1; j <= 3500; j++){ // n
            ll cn = 4*i*j - N*j - N*i;
            ll mo = N*i*j;
            if(cn <= 0) continue;
            if(mo % cn != 0) continue;
            else{
                ll k = mo / cn;
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
}