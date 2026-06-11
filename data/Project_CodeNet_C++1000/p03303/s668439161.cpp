#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define debug(x) cerr << #x << ": " << x << '\n'

int main()
{
    string S;
    int w;
    cin >> S >> w;
    for (int i = 0; i < S.size(); ++i)
    {
        if (i % w == 0)
        {
            cout << S[i];
        }
    }
    cout << endl;
}
