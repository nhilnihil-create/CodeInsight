#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int x;
    cin >> x;
    int ans = 0;
    if(x == 1) cout << 1 << endl;
    else{
        for(int i = 2; i*i <= x; i++){
            int v = i;
            while(v * i <= x){
                v *= i;
            }
            if(ans < v) ans = v;
        }
        cout << ans << endl;
    }
    return 0;
}