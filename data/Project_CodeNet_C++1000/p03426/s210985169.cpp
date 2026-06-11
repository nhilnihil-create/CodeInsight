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
    int h,w,d;
    cin >> h >> w >> d;
    int n = h * w;
    vector<int> vx(n+1), vy(n+1),m(n+1);
    REP(i,h)REP(j,w){
        int a;
        cin >> a;
        vx[a-1] = i;
        vy[a-1] = j;
    }
    REP(i,d){
        for (int j = 0+i; j <= n-d;j+=d){
            m[j+d]=abs(vx[j + d] - vx[j]) + abs(vy[j + d] - vy[j])+m[j];
        }
    }
    int q;
    cin >> q;
    REP(i,q){
        int l, r;
        cin >> l>> r;
        cout << m[r-1]-m[l-1] << "\n";
    }
    return 0;
}