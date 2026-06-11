#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
    while(b != 0){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    int n, sx, x;
    cin >> n >> sx >> x;
    int ans = abs(x - sx);
    sx = x;
    for(int i = 1; i < n; i++){
        cin >> x;
        ans = gcd(ans, abs(x - sx));
        sx = x;
    }
    cout << ans << endl;
    return 0;
}