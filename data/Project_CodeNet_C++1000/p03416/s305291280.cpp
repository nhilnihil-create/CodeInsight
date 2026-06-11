#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int A, B;
    cin >> A >> B;
    int res = 0;
    for (int i = A; i <= B; i++)
    {
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t)
            res++;
    }
    cout << res << endl;
    return 0;
}