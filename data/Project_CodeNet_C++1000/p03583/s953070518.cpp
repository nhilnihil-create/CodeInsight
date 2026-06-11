#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll N;
    cin >> N;
    ll h,w,n;
    for(h = 1;h <= 3500;++h){
        for(w = 1;w <= 3500;++w){
            ll tmp1 = N*h*w;
            ll tmp2 = 4*h*w - N*(w + h);
            if(tmp2 <= 0) continue;
            else if(tmp1%tmp2 == 0){
                ll n = tmp1/tmp2;
                cout << h << " " << n << " " << w << endl;
                return 0;
            }
        }
    }

    return 0;
}