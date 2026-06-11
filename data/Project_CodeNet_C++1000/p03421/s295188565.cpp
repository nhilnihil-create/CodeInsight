#include <bits/stdc++.h>
using namespace std;

long long n, a, b;

int main()
{
    cin >> n >> a >> b;

    if (a+b>n+1 || a*b < n)
    {
        cout << "-1\n";
        return 0;
    }
    if (a == 1)
    {
        for (int i=n; i>=1; i--)
        {
            cout << i << " ";
        }
        return 0;
    }
    vector<int> len(a, (n-b)/(a-1));
    len[0] = b;
    int c = accumulate(len.begin(), len.end(), 0);
    for (int i=1; i<= n - c; i++)
    {
        len[i]++;
    }
    int now = 0;
    for (auto l : len)
    {
        now += l;
        for (int i=0; i<l; i++)
        {
            cout << now - i << " ";
        }
    }

    cout << endl;
    return 0;
};