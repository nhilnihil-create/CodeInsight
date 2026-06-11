#include <bits/stdc++.h>
using namespace std;
int a[10], n, f[100][10], result = 0, p[100][11];
void compare(int n) {
    bool zero = true;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] == 1) 
        {
            zero = false;
            break;
        }
    }
    if (zero == true) return;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j < 10; j++)
            if (f[i][j] == 1 && a[j] == 1) k++;
        s += p[i][k];
    }
    result = max(result, s);
    return;
}
void back(int pos) {
    if (pos == 10) compare(n);
    else
    {
        for (int i = 0; i < 2; i++)
        {
            a[pos] = i;
            back(pos + 1);
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 10; j++) f[i][j] = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 11; j++) p[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 10; j++) cin >> f[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 11; j++) cin >> p[i][j];
    for (int i = 0; i < n; i++)
    {
        if (f[i][0] == 1) result += p[i][1];
        else result += p[i][0];
    }
    back(0);
    cout << result;
}