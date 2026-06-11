#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int GCD(int x, int y) {
    if (y > x) swap(x,y);
    if (y == 0) return x;
    else return GCD(y, x % y);
}

int main(void){
    int n, X;
    cin >> n >> X;
    
    vector<int> x(n+1);
    for (int i = 0; i < n; i++) cin >> x[i];
    
    x[n] = X;
    
    if (n == 1){
        cout << abs(x[0] - x[1]) << endl;
        return 0;
    }
    
    // n >= 2
    sort(x.begin(),x.end());
    vector<int> diff(n);
    for (int i = 0; i+1 <= n; i++) diff[i] = x[i+1]-x[i];
    
    int ans =  GCD(diff[0],diff[1]);
    
    for (int i = 0; i < n; i++) ans = GCD(ans,diff[i]);
    cout << ans << endl;
}
