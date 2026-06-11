#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int, int> P;
typedef long long ll;

int main()
{
    int a, b;
    cin >> a >> b;

    if (b >= a)
        cout << a << endl;
    else
        cout << a - 1 << endl;
}