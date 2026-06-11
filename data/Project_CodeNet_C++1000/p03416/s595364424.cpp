#include <bits/stdc++.h>
using namespace std;
//
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mx 100010
#define pi acos(-1)
#define endl '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
//
int main()
{
    ll a, b, i, l, j, k, c, count = 0;
    string s;

    cin >> a >> b;
    for (i = a; i <= b; i++)
    {
        s = to_string(i);
        l = s.length();

        j = 0;
        k = l;
        k--;
        c = 0;
        while (k >= 0)
        {
            if (s[j] == s[k])
            {
                c++;
            }
            j++;
            k--;
        }
        if (c == l)
            count++;
    }
    cout << count << endl;
}
