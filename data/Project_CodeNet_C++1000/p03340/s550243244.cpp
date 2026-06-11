#include <iostream>
#include <vector>

using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a = vector<int>(n + 1);
    vector<int> su = vector<int>(n + 1);
    vector<int> sv = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        su[i] = su[i - 1] + a[i];
        sv[i] = sv[i - 1] ^ a[i];
    }
    int s = 1, t = 1;
    i64 an = 0;
    while (t <= n)
    {
        if (su[t] - su[s - 1] == (sv[t] ^ sv[s - 1]))
        {
            t++;
            an += t - s;
            continue;
        }
        do
        {
            s++;
        } while (su[t] - su[s - 1] != (sv[t] ^ sv[s - 1]));
    }
    cout << an << "\n";
}