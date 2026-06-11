#include <iostream>
using namespace std;
int ans = 0;
void find(int n, long long sub, bool t, bool f, bool s)
{
    if(sub > n)
    {
        return;
    }
    if(t && s && f)
    {
        ans++;
    }
    find(n, sub * 10 + 3, true, f, s);
    find(n, sub * 10 + 5, t, true, s);
    find(n, sub * 10 + 7, t, f, true);
}
int main()
{
    int n;
    cin >> n;
    find(n, 0, false, false, false);
    cout << ans << endl;
    return 0;
}
