#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const long long INF = 1LL << 60;

int main()
{
    string n;
    cin >> n;
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] == '9')
            n[i] = '1';
        else if (n[i] == '1')
            n[i] = '9';
    }
    cout << n << endl;
    return 0;
}
