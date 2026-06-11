#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

int main()
{
    string S;
    cin >> S;

    if (S.length() == 2)
    {
        cout << S << endl;
        return 0;
    }
    else
    {
        std::reverse(S.begin(), S.end());
        cout << S << endl;
    }
}