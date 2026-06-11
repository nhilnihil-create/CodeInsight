#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    ll N; cin >> N;

    for(ll n = 1; n <= 3500; n++) {
        for(ll w = 1; w <= 3500; w++) {
            ll A = w * n, B = w + n;
            if((4 * A - B*N) == 0)continue;
            if(A * N % (4 * A - B*N) == 0) {
                if((A * N) / (4 * A - B * N) <= 0)continue; 
                cout << (A * N) / (4 * A - B * N) << " " << n << " " << w << endl;
                return 0;
            }
        }
    }
    return 1;
}