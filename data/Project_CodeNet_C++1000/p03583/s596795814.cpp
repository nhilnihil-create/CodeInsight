#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////


int main() {
    ll N; cin >> N;
    
    repf(h,1,3501) repf(n,h,3501) {
        ll a = 4*h*n-(h+n)*N;
        ll b = h*n*N;
        if (a > 0 && b%a == 0) {
            cout << h << ' ' << n << ' ' << b/a << endl;
            return 0;
        }
    }
    return 0;
}