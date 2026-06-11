#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
        OP("Hello World");
    else
    {
        int a, b;
        cin >> a >> b;

        OP(a + b);
    }
    return 0;
}