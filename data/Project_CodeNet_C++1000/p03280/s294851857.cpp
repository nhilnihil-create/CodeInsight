#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define Cout(s) cout << s << endl;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1ll << 60;
ll MOD = 1e9 + 7;

int main()
{

    int a, b;
    cin >> a >> b;

    Cout(a * b - a - b + 1);
    return 0;
}