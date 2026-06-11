#include <bits/stdc++.h>
using namespace std;

using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)

int main()
{
    lint x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lint x, y;
    x = x2 - x1;
    y = y2 - y1;
    lint x3 = x2 - y,y3 = y2 + x;
    lint x4 = x1 - y, y4 = y1 + x;
    lint ans=0;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
    return 0;
}