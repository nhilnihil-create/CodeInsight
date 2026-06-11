#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

typedef long long ll;
//typedef pair<int,int> Pint;
typedef pair<ll, ll> P;
//typedef pair<ll, pair<ll, ll>> P;
//typedef tuple<int,int,int> T;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define revrep(i, n) for(ll i = n-1; i >= 0; i--)
#define pb push_back
#define f first
#define s second
ll INFL = 1LL << 60;//10^18 = 2^60
int INF = 1 << 30;//10^9
ll MOD = 1e9 + 7;
//ll MOD  = 998244353;
vector<ll> dy = {0, 0, 1, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, -1, 0, 0, 1, -1, 1, -1, 0};

ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}

ll pow_mod(ll x, ll k){
  x %= MOD; x += MOD; x %= MOD;
  ll res = 1;
  while(k > 0){
    if(k % 2){
      res *= x; res %= MOD;
    }
    x *= x; x %= MOD;
    k /= 2;
  }
  return res;
}
ll inverse(ll x){return pow_mod(x, MOD - 2);};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll x, ll y){return x / gcd(x, y) * y % MOD;};

vector<ll> A;
ll N;

bool Judge(ll x){
    x--;//x文字まで使える=>x番目の文字まで使える
    vector<P> S;
    S.pb({0, A[0]});
    for(int i = 1; i < N; i++){
        if(A[i-1] < A[i]){
            if(S.back().f == 0) S.back().s += A[i] - A[i-1];
            //最後がaならaの数を増やす
            else S.pb({0, A[i] - A[i-1]});
            //aを付け足す
        }else{
            ll cnt = 0;
            vector<P> T;
            rep(j, S.size()){
              if(S[j].s == 0) continue;
              if(cnt == A[i]) break;
              if(cnt + S[j].s <= A[i]){
                if(S[j].s != 0)T.pb(S[j]);
                cnt += S[j].s;
              }else{
                T.pb({S[j].f, A[i] - cnt});
                cnt += A[i] - cnt;
              }
            }
            S = T;

            //SはA[i]文字、これを辞書順で１つ大きくする
            bool l = 0;
            rep(j, S.size()){
              if(S[j].s == 0) continue;
              if(S[j].f != x) l = 1;
            }
            if(l == 0) return 0;

            cnt = 0;
            revrep(j, S.size()){
              if(S[j].s == 0) continue;
              if(S[j].f == x){
                cnt += S[j].s;
              }else{
                S.erase(S.begin()+j+1, S.end());
                S[j].s--;
                S.pb({S[j].f+1, 1});
                if(cnt != 0) S.pb({0, cnt});
                break;
              }
            }
        }

    }
    return 1;
}


int main(void){
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    ll ng = 0, ok = N+1;
    ll mid;
    while(ok - ng > 1){
        mid = (ng + ok) / 2;
        if(Judge(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;

}
