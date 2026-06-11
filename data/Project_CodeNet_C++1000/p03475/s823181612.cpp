#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int c[n - 1], s[n - 1], f[n - 1];
    for (int i = 0; i < n - 1; i++)
        cin >> c[i] >> s[i] >> f[i];
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        for (int j = i; j < n - 1; j++)
        {
            if (t < s[j]) t = s[j];
            else if (t % f[j] != 0) t = t + f[j] - t % f[j];
            t += c[j];
        }
        cout << t << endl;
    }
}