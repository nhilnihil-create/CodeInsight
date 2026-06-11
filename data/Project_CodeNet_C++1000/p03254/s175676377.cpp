#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (i == n-1) {
            if (x != a[i]) break;
        }
        if (x < a[i]) break;
        x = x - a[i];
        cnt++;
    }
    cout << cnt << '\n';
   return 0;
}