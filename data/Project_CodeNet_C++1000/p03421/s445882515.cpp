#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    long long a, b;
    cin >> n >> a >> b;

    if (n < a + b - 1 || n > a * b)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    for (int i = n; i > 0; i -= a)
    {
        for (int j = a - 1; j >= 0; j--)
        {
            if (i - j > 0)
            {
                ans.push_back(i - j);
            }
        }
    }

    int lds = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (ans[i] > ans[i + 1])
        {
            lds++;
        }
    }

    if (lds != b)
    {
        for (int i = n - 2; i >= 0; i--)
        {
            if (ans[i] < ans[i + 1])
            {
                lds++;
            }
            if (lds == b)
            {
                sort(ans.begin() + i, ans.end());
                reverse(ans.begin() + i, ans.end());
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << ans[i];
    }

    cout << endl;

    return 0;
}
