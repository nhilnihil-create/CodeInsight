#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
#include<numeric>
using namespace std;
typedef long long ll;
//ll mod = 1e9+7;
ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    ll N;
    cin >> N;
    for ( ll i = 1; i <= 3500; ++i ) {
        for ( ll j = 1; j <= 3500; ++j ) {
            ll tmp_num = N * i * j;
            ll div_num = 4 * i * j - N * i - N * j;
            if ( div_num <= 0 ) {
                continue;
            }
            if ( tmp_num % div_num == 0 ) {
                printf("%d %d %d\n", i, j, tmp_num / div_num );
                return 0;
            }
        }
    }
    return 0;
}
