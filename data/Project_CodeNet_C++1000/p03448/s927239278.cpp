#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    
    int a, b, c;
    cin >> a >> b >> c;
    int x;
    cin >> x;
    int ans = 0;
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            for(int k = 0; k <= c; k++){
                if(x == 500*i + 100*j + 50*k) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}