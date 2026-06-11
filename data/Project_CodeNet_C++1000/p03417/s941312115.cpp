#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, w; cin >> n >> w;
    long long ans = 0;
    if(n == 1 && w == 1) ans = 1;
    else if(n == 1 || w == 1) ans = n * w - 2;
    else if(n == 2 || w == 2) ans = 0;
    else ans += (n-2)*(w-2);
    cout << ans << endl;
}