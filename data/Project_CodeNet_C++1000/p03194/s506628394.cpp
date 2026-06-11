#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <set>
#include <algorithm>  // std::copy()
#include <functional>  // std::greater<T>()
#include <utility>  // std::swap()
#include <numeric>  // accumulate(ALL(vec), 0)  0 は初期値
#include <cmath>
#include <climits>  // INT_MIN
#include <cctype>  // std::isdigit()
using namespace std;

#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (int i=0; i < (int)(n); i++)  // 0 ~ n-1
#define REPN(i, n) for (int i=1; i <= (int)(n); i++)  // 1 ~ n
#define MIN(vec) min_element(ALL((vec)))  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(ALL((vec)))
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(ALL((vec)), 0)  // 0 は初期値
#define COPY(vec1, vec2) copy(ALL(vec1), back_inserter(vec2))  // vec1をvec2にコピーする vec2は空にしておく必要あり
typedef long long ll;

const int MOD = 1000000007;  // 1 000 000 007

vector< pair<ll, ll> >  primeFactorization(ll n) {
    // 平方根を保存
    double s = floor(sqrt(n));
    
    ll r = 0;
    
    vector< pair<ll, ll> > result;
    
    // 2から平方根までの素因数を求める
    for (int i = 2;i <= s;i++) {
        if ((n % i) == 0) {
            r = 0; // 指数カウンタクリア
            do {
                
                r++; // 指数カウンタプラス
                
                n = n / i;
                
            } while ((n % i) == 0);
            
            // 素因数iを指数とともに保存
            result.emplace_back(make_pair(i, r));
        }
        
    }
    
    // 残った素数を追加
    if (n > s) {
        result.emplace_back(make_pair(n, r));
    }
    
    return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, P;
    cin >> N >> P;
    
    // calculation
    if (P == 1) {
        cout << 1 << "\n";
    } else if (N == 1) {
        cout << P << "\n";
    } else {
        vector< pair<ll, ll> > vec;
        vec = primeFactorization(P);
        ll len = (ll)vec.size();
        
        ll ans = 1;
        vector<ll> res;
        for (ll i = 0; i < len; ++i) {
            ll ex = vec[i].second;
            if (ex >= N) {
                ans *= pow(vec[i].first, ex/N);
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
