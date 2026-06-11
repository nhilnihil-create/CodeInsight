#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int func(int n){
    int res = n%10;
    while(n/10 != 0){
        n /= 10;
        res += n%10;
    }
    return res;
}
int main(){

    int n, a, b;
    cin >> n >> a >> b;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int v = func(i);
        if((v >= a) && (v <= b)) {
            ans += i; 
        }
    }
    cout << ans << endl;

    return 0;
}