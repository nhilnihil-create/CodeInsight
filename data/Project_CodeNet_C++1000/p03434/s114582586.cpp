// https://atcoder.jp/contests/abc088/tasks/abc088_b
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>()); // 降順
    int s = 0;
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        s += c * a[i];
        c = -c;
    }
    cout << s << endl;
    return 0;
}