#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

map<int, int> mp;
void prime_factorize(long long N) {
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        mp[a] += ex;
    }
    if (N != 1) mp[N]++;
}

int main() { 
   int n; cin >> n;
   fo(i, 1, n+1)prime_factorize(i);

   ll _74 = 0, _24 = 0, _14 = 0,_4 = 0, _2 = 0;
   for(auto m: mp){
       int num = m.second;
       if(num >=74) _74++;
       if(num >=24) _24++;
       if(num >=14) _14++;
       if(num >=4) _4++;
       if(num >=2) _2++;
   }
   ll res = 0;
   res += _74;
   res += _24 * (_2-1);
   res += _14 * (_4-1);
   res += (_4*(_4-1)/2)*(_2-2);

   cout << res << ln;
}




