#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int x; cin >> x;

    for(int i = x; i > 0; i--){
        for(int j = 2; j * j <= i; j++){
            int n = j;
            while(n < i) n *= j;
            if(n == i){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
    return 0;
}
