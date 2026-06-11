#include <bits/stdc++.h>
#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    using namespace std;
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a.at(i);
    }

    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            res = max(res, abs(a.at(j) - a.at(i)));
        }
    }

    cout << res << endl;
    return 0;
}