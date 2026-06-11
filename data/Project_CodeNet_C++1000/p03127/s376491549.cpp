#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
    if (y > x) swap(x,y);
    if (y == 0) return x;
    else return gcd(y, x % y);
}

int main(void){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = gcd(a[0],a[1]);
    
    for (int i = 0; i < n; i++) ans = gcd(ans,a[i]);
    
    cout << ans << endl;
}
