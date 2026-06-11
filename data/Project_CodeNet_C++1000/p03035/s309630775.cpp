#include <iostream>
using namespace std;
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll;
#define fin(ans) cout << (ans) << '\n'

int main()
{
    int A,B;
    cin >> A >> B;
    if(A < 6){
        fin(0);
    }else if(A < 13){
        fin(B/2);
    }else{
        fin(B);
    }
    return 0;
}