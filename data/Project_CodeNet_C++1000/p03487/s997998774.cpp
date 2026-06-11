#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, k = 0, s = 0;
    cin >> n;
    long long a[n], p[n];
    for (long long i = 0; i < n; i++) 
    {
        cin >> a[i];
        p[i] = 0;
    }
    p[0] = 1;
    sort(a, a + n);
    for (long long i = 1; i < n; i++)
    {
        bool increase = false;
        if (a[i] != a[i - 1])
        {
            increase = true;
            if (p[k] < a[i - 1]) s = s + p[k];
            if (p[k] > a[i - 1]) s = s + p[k] - a[i - 1];
            k++;
            p[k] = 1;
        }
        else p[k]++;
        if (i == n - 1 && increase == false)
        {
            if (p[k] < a[i - 1]) s = s + p[k];
            if (p[k] > a[i - 1]) s = s + p[k] - a[i - 1];
        }
    }
    if (p[k] == 1)
    {
        if (p[k] < a[n - 1]) s = s + p[k];
        if (p[k] > a[n - 1]) s = s + p[k] - a[n - 1];
    }
    if (n == 1 && a[0] != 1) cout << '1';
    else cout << s;
}