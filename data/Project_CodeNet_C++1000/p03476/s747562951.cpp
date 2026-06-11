#include <bits/stdc++.h>
using namespace std;
int main() {
    bool p[100001];
    int c[100001], q, l, r;
    for (int i = 0; i < 100001; i++)
    {
        p[i] = false;
        c[i] = 0;
    }
    for (int i = 2; i < 100001; i++)
    {
        if (p[i] == false)
            for (int j = i * 2; j < 100001; j += i) p[j] = true;
    }
    for (int i = 3; i < 100001; i++)
        if (p[i] == false && p[(i + 1) / 2] == false) c[i]++;
    for (int i = 3; i < 100001; i++) c[i] += c[i - 1];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        cout << c[r] - c[l - 1] << endl;
    }
}