#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    int a[m];
    vector<bool> check(n);
    for (int i=0; i<m; i++) {
        cin >> a[i];
        check[a[i]] = 1;
    }
    int forward = 0;
    for (int i=x; i<n; i++) {
        if (check[i]) forward++;
    }
    int backward = 0;
    for (int i=x; i>0; i--) {
        if (check[i]) backward++;
    }
    int ans = min(forward, backward);
    cout << ans << '\n';
   
    return 0;
}