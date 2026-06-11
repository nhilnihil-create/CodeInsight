#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<ll,ll> P;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
#define INF 1e9
const int MOD = 998244353;

// bit全探索
int main(void){
    string org;
    char op[3];
    int res = 0;
    cin >> org;

    FOR(b,0,(1 << 3)){
        res = org[0] - '0';
        REP(i,3){
            if((b >> i) & 1){
                res += (org[i+1] - '0');
                op[i] = '+';
            }else{
                res -= (org[i+1] - '0');
                op[i] = '-';
            }
        }
        if(res == 7) break;
    }
    cout << org[0] << op[0] << org[1] << op[1] << org[2] << op[2] << org[3] << "=7" << endl;
    return 0;
}