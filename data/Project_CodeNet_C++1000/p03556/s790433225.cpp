#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ll n; cin >> n;

    // for(int i = n; i > 0; i--){
    //     if(floor(sqrt(i)) == sqrt(i)){
    //         cout << i << endl;
    //         return 0;
    //     }
    // }
    for(int i = 1; ; i++){
        if(i * i > n){
            cout << (i - 1) * (i - 1) << endl;
            return 0;
        }
    }
}
