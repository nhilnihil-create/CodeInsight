#include "bits/stdc++.h"
#include <math.h>
using namespace std;
void solve(){
    long long x, y;
    cin >> x >> y;
    if(x % y == 0){
        cout << -1 << endl;
    }
    else{
        for(long long i = 1; i < y; i++){
            if(x * i % y != 0){
                cout << x * i << endl;
                break;
            }
        }
    }
}
int main(){
    solve();
    return 0;
}