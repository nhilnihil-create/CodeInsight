#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

const long long INF = 1LL << 60;

int main()
{
    string s;
    int ans = 0;
    cin >> s;
    for (int i = 0; i < 4; i++)
    {
        if (s[i] == '+')
            ans++;
        else
            ans--;
    }
    cout << ans << endl;
    return 0;
}
