#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> P;
#define REP(i, x, n) for(int i = x ; i < n ; ++i)
#define rep(i, n) for(int i = 0 ; i < n ; ++i)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort((x).begin(), (x).end())

const int IINF = 1e9 + 10;
const long long LLINF = (long long)1e18 + 10;
const long long MOD = (long long)1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int main(){
    lint n, p;
    cin >> n >> p;
    map<lint, lint> mp;
    for(lint i = 2 ; i * i <= p ; ++i){
        while(p % i == 0){
            ++mp[i];
            p /= i;
        }
    }
    if(p > 1){
        ++mp[p];
    }
    lint ans = 1;
    for(auto x : mp){
        ans *= pow(x.first, x.second / n);
    }
    cout << ans << endl;
    return 0;
}