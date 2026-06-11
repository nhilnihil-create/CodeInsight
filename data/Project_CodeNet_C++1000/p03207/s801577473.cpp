#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int p[N];
    int ans = 0;
    int max_p = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
        ans += p[i];
        max_p = max(max_p, p[i]);
    }
    cout << ans - max_p / 2 << endl;
}