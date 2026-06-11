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
    lint n;cin >> n;
    int t2=0, x2=0, y2=0;
    vector<int> tv(n), xv(n), yv(n);
    REP(i,n){
        cin >> tv[i] >> xv[i] >> yv[i];
    }
    REP(i,n){

        int t = tv[i], x = xv[i], y = yv[i];
        int tmp = (t - t2 - (abs(x2 - x) + abs(y2 - y)));
        if (tmp% 2 == 0&&tmp>=0)
        {
        }
        else
        {
            cout << "No"
                 << "\n";
            return 0;
        }

        t2 = t;
        x2 = x;
        y2 = y;
    }
    cout << "Yes" << "\n";
    return 0;
}