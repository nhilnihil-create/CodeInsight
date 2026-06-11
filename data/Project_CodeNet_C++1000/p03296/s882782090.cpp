#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int N, prev;
    int count = 1;
    int ans = 0;
    cin >> N;
    cin >> prev;
    for (int i = 0; i < N - 1; ++i)
    {
        int now;
        cin >> now;
        if (now == prev)
        {
            ++count;
        }
        else
        {
            ans += count / 2;
            count = 1;
        }
        prev = now;
    }
    ans += count / 2;
    cout << ans << endl;
}
