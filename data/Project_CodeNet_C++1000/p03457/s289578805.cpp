#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string ans = "Yes";
    int N;
    cin >> N;
    vector<int> x(N), y(N), t(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> t[i] >> x[i] >> y[i];
    }
    for (int i = 0; i < N; ++i)
    {
        if (i == 0)
        {
            continue;
        }
        else
        {
            x[i] -= x[i - 1];
            y[i] -= y[i - 1];
            t[i] -= t[i - 1];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        if (abs(x[i]) + abs(y[i]) <= t[i] && (abs(x[i]) + abs(y[i])) % 2 == t[i] % 2)
        {
            continue;
        }
        else
        {
            ans = "No";
        }
    }
    cout << ans << endl;
}