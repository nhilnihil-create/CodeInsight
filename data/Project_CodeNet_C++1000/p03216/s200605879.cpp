#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define Yes(condition) if(condition){ cout << "Yes" << '\n'; }else{ cout << "No" << '\n'; }
#define YES(condition) if(condition){ cout << "YES" << '\n'; }else{ cout << "NO" << '\n'; }
#define yes(condition) if(condition){ cout << "yes" << '\n'; }else{ cout << "no" << '\n'; }




int main() {
    ll n, q;
    string s;
    cin >> n >> s >> q;
    REP(aaa, q){
        ll k;
        cin >> k;
        
        ll d_cnt = 0, m_cnt = 0, dm = 0, ans = 0;
        REP(i, n){
            if(s[i] == 'D'){
                d_cnt++;
            }
            else if(s[i] == 'M'){
                dm += d_cnt;
                m_cnt++;
            }
            else if(s[i] == 'C'){
                ans += dm;
            }
            
            if(i - k + 1 >= 0){
                if(s[i - k + 1] == 'D'){
                    d_cnt--;
                    dm -= m_cnt;
                }
                else if(s[i - k + 1] == 'M'){
                    m_cnt--;
                }
            }
        }
        cout << ans << endl;
    }
}
