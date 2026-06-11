#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll ans = 0;
    ll N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        ll temp;
        cin >> temp;
        if (temp % 2 == 0)
        {
            while (temp % 2 == 0)
            {
                temp = temp / 2;
                ++ans;
                if (temp % 2 == 1)
                {
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}
