#include <iostream>
using namespace std;
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll;
#define fin(ans) cout << (ans) << '\n'
//x+1 = rx - D
int main()
{
    int r, D, x2000;
    cin >> r >> D >> x2000;
    int ans = x2000;
    REP(i,10){
        ans = r* ans -D;
        fin(ans);
    }
    return 0;
}