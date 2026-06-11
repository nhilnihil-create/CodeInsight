// https://atcoder.jp/contests/arc098/tasks/arc098_c

#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <set>
 
using namespace std;

using INT = long long int;
using VEC = std::vector<INT>;
const INT INF = INT(1) << 60;

#define FOR(i, N) for( INT i = 0; i < N; i++ )
#define RANGE(v) begin(v), end(v)

int main(void){
    INT N, K, Q;

    cin >> N >> K >> Q;
    VEC ax(N);
    
    FOR(i, N) cin >> ax[i];

    INT ans = INF;

    for( auto m : ax ){
        VEC tmp, ret;
        for( auto a : ax ){
            if ( a < m ){
                auto s = tmp.size();
                if( s >= K ) {
                    std::sort( RANGE(tmp) );
                    for( INT i = 0; i < Q && i < s-K+1; i++ ){
                        ret.push_back(tmp[i]);
                    }
                }
                else { /* NOP */ }
                tmp.clear();
            } else {
                tmp.push_back(a);
            }
        }

        // last
        auto s = tmp.size();
        if( s >= K ) {
            std::sort( RANGE(tmp) );
            for( INT i = 0; i < Q && i < s-K+1; i++ ){
                ret.push_back(tmp[i]);
            }
        }

        if( ret.size() >= Q ){
            std::sort( RANGE(ret) );
            ans = std::min( ans, (ret[Q-1] - ret[0]) );
        }
    }

    cout << ans << endl;

}

