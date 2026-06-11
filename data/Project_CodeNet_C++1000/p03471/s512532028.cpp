#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (ll i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    ll N, Y;
    cin >> N >> Y;
    for(int i=0; i<=N; ++i){
        for(int j=0; j<=N-i; ++j){
            ll yen = 10000*i+5000*j;
            int z;

            if((Y-yen)%1000==0) z = (Y-yen)/1000;
            else continue;
            if(i+j+z==N){
                cout << i << " " << j << " " << z << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}
