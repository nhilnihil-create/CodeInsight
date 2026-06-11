#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, maxv, minv;
    cin >> n >> a >> b;
    if (a + b < n)
    {
        minv = 0;
    }
    else if (a + b >= n)
    {
        minv = a + b - n;
    }
    maxv = min(a, b);
    cout << maxv << " " << minv << endl;
    
}