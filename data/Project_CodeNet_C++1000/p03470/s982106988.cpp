#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k = 0, m = 0;
    cin >> n;
    int d[n], p[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> d[i];
        p[i] = 0;
    }
    p[0] = 1;
    sort(d, d + n);
    for (int i = 1; i < n; i++)
    {
        if (d[i] != d[i - 1]) 
        {
            k++;
            p[k] = 1;
        }
        else p[k]++;
    }
    for (int i = 0; i < n; i++)
        if (p[i] > 0) m++;
    cout << m;
}