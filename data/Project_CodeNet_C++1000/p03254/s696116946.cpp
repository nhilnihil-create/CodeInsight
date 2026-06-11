#include <bits/stdc++.h>

using namespace std;

int n, x, a, ans=0;
vector<int> as;

int main()
{    cin >> n >> x;
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        as.push_back(a);
    }

    sort(as.begin(), as.end());

    long long s = 0;
    for(int i = 0; i < n; ++i)
    {
        s += as[i];
        if(s <= x)
        {
            ans++;
        }
    }
    if(ans == n && s < x)
        ans--;

    cout << ans << endl;

    return 0;
}
