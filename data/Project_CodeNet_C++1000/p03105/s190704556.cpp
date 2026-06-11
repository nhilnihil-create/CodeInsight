#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << min(b / a, c) << endl;
}