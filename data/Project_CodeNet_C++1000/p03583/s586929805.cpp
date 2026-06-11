#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<ll> A(MAXN, 0);

signed main(){
    cin >> N;
    for(ll i=1;i<=3500;i++) {
        for(ll j=1;j<=3500;j++) {
            //cout << "OK" << endl;
            if((4*i*j-N*i-N*j)>0) {
                if((N*i*j)%(4*i*j-N*i-N*j)==0) {
                    cout << i << " " << j << " " << (N*i*j)/(4*i*j-N*i-N*j) << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}