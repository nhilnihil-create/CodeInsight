#include <iostream>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool poss = a[0] == 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - 1 > a[i - 1])
            poss = false;
    }
    if (poss)
    {
        int ptr = 1;
        long long ans = 0;
        while (ptr < n)
        {
            while (ptr + 1 < n && a[ptr + 1] == a[ptr] + 1)
            {
                ptr++;
            }
            ans += a[ptr];
            ptr++;
        }
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
