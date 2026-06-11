#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    long long x,y; cin >> x >> y;
    long long n = x;
    int ans = 0;
    while(n <= y){
        ans++;
        n *= 2;
    }
    cout << ans << endl;
}