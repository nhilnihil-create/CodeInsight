#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k, x, y, ans=0;
    cin >> n >> k;
    if(k%2==0) {
        x=n/k;
        y=(n+k/2)/k;
        ans+=x*x*x;
        ans+=y*y*y;

    }
    else {
        x=n/k;
        ans=x*x*x;
    }
    cout << ans;
}