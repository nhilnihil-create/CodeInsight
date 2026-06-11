#include <iostream>
#include<map>
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)

using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int A,B,T;
    int ans;
    cin >> A >> B >> T;
    ans = T/A*B;
    fin(ans);

    return 0;
}