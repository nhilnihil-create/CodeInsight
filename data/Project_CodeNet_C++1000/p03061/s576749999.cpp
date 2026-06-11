#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int suml[maxn], sumr[maxn];

int gcd(int x, int y) {
    return y==0?x:gcd(y, x%y);
}

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i]; 
    }

    if (n==1) {
        cout << a[1] << endl;
        return 0;
    }

    suml[0] = 0;
    for (int i=1; i<=n; i++) {
        suml[i] = gcd(a[i], suml[i-1]);
    }

    sumr[n] = a[n];
    sumr[0] = 0;
    for (int i=n-1; i>=1; i--) {
        sumr[i] = gcd(a[i], sumr[i+1]);
    }

    int ans = max(suml[n-1], sumr[2]);
    for (int i=2; i<n; i++) {
        ans = max(ans, gcd(suml[i-1], sumr[i+1]));
    }
    cout << ans << endl;
    return 0;
}