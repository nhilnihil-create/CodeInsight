#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <iomanip>

#define DEBUG 0
#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

int main(){
#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int N;
    cin >> N;

    int res = 0, ren = 1;
    int be = 99999;
    REP(i,N)
    {
        int a;
        cin >> a;

        if(be == a)
        {
            ++ren;
        }
        else
        {
            be = a;
            res += ren/2;
            ren = 1;
        }
    }
    res += ren/2;

    cout << res << endl;
    return 0;
}

