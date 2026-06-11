#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>
using namespace std;
using ll = long long;
constexpr ll INF = 1010000000000000017LL;
constexpr ll mod = 1000000007;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int x;cin>>x;
    int ans = 1;
    int tmp;

    for (int b = 1; b <= x; ++b)
    {   
        tmp = b;
        for (int p = 2; p <= x; ++p)
        {
            tmp *= b;
            if(tmp<=x) {
                ans = max(ans,tmp);

                // cout<<b<<"**"<<p<<'='<<ans<<endl;
            } else {
                break;
            }
        }
        
    }
    cout<<ans<<endl;
    
}
