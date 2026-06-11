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
    int n, q;
    char s[1000001];
    scanf("%d %s %d", &n, s, &q);
    for(int a = 0; a < q; a++){
        int k;
        scanf("%d", &k);
        
        int d = 0, m = 0;
        long long x = 0, z = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'D'){
                d++;
            }
            else if(s[i] == 'M'){
                x += d;
                m++;
            }
            else if(s[i] == 'C'){
                z += x;
            }
            
            if(i - k + 1 >= 0){
                if(s[i - k + 1] == 'D'){
                    d--;
                    x -= m;
                }
                else if(s[i - k + 1] == 'M'){
                    m--;
                }
            }
        }
        printf("%lld\n", z);
    }
}
