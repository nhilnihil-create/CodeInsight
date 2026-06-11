#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int xl[n], yl[m];
    for (int i = 0; i < n; i++)
        cin >> xl[i];
    for (int i = 0; i < m; i++)
        cin >> yl[i];
    
    sort(xl, xl+n);
    sort(yl, yl+m);
    if (xl[n-1]<yl[0] && x<yl[0] && y>xl[n-1])
        cout << "No War" << endl;
    else
        cout << "War" << endl;
}