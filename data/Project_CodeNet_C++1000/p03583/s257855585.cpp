#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    if(n==2){
        cout << "1 2 2" << "\n";
        return 0;
    }

    for(ll w = 3*n/4; w*4>n ; w--) {
        for(ll h = w; h*(4*w-n) <=2*n*w ; h++) {
            ll u=n*h*w;
            ll b=4*w*h-n*h-n*w;
            if(u%b==0 && b>0){
                cout << w << " " << h << " " << u/b << "\n";
                return 0;
            }
        }
    }

    return 0;
}