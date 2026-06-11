#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;

//整数は重複なく書かれていた
int main(){

    int H,W,D;
    cin >> H >> W >> D;
    vector <int> px(H*W+1);
    vector <int> py(H*W+1);
    vector <int> d(H*W+1, 0);
    int cnt = 0;
    REP(i,H)
    {
        REP(j,W)
        {
            int t;
            cin >> t;
            py[t] = j;
            px[t] = i;
        }
    }
    for(int i = D+1; i <= H*W; ++i)
    {
        int ma = abs(py[i] - py[i-D]) + abs(px[i]-px[i-D]);
        //D+1へは1+maが必要
        d[i] = d[i-D] + ma;
    }


    int Q;
    cin >> Q;
    REP(i,Q)
    {
        int l,r;
        cin >> l >> r;
        int res;
        res = d[r] - d[l];

        cout << res << endl;
    }

    return 0;
}
