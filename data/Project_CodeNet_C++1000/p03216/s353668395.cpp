#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
#define PI acos(-1.0);

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
    int N; cin >> N;
    string s; cin >> s;
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        int d = 0,m = 0;
        ll dm = 0;
        ll ans = 0;
        rep(i,N){
            if(s[i] == 'D') d++;
            if(s[i] == 'M'){
                m++;
                dm += d;
            }
            if(i >= k){
                if(s[i-k] == 'D'){
                    d--;
                    dm -= m;
                }
                if(s[i-k] == 'M'){
                    m--;
                }
            }
            if(s[i] == 'C'){
                ans += dm;
            }
        }
        cout << ans << endl;
    }
}

