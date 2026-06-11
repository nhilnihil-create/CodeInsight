#include <bits/stdc++.h>
using namespace std;
int m_calc(int a, int b)
{
    int max = (a > b) ? a : b;
    int min = (a < b) ? a : b;
    return max * 10 + min;
}
int main()
{
    int a, b, c, ans;
    cin >> a >> b >> c;
    int min = (a < b) ? a : b;
    min = (min < c) ? min : c;
    if (min == a)
        ans = m_calc(b, c) + a;
    else if (min == b)
        ans = m_calc(a, c) + b;
    else if (min == c)
        ans = m_calc(a, b) + c;
    cout << ans << endl;
}