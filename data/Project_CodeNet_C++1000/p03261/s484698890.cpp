#include <bits/stdc++.h>

using namespace std;

bool solve(const vector<string> &W)
{
    const int n = W.size();

    for (int i = 0; i < n - 1; ++i)
    {
        if (W[i].back() != W[i + 1].front())
        {
            return false;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (W[i] == W[j])
            {
                return false;
            }
        }
    }
    return true;
}

vector<string> input()
{
    int n;
    cin >> n;
    vector<string> W(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> W[i];
    }
    return W;
}

int main()
{
    const vector<string> W = input();
    if (solve(W))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}