#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = n;
    for (int i = 0; i <= n; i++)
    {
        int cnt = 0;
        int t = i;
        while (t > 0)
            cnt += t % 6, t /= 6;
        t = n - i;
        while (t > 0)
        {
            cnt += t % 9, t /= 9;
        }
        // cout << "cnt: " << cnt << endl;
        if (res > cnt)
        {
            res = cnt;
        }
    }
    cout << res << endl;
    return 0;
}