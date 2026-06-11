#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define repreverse(i, start, end) for (long long i = start; i >= end; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) ((long long)(x).size())
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vllvll = vector<vll>;
using vc = vector<char>;
using pll = pair<ll, ll>;
template<class T>void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T>void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T, class U>bool haskey(T mp, U key) { return mp.find(key) != mp.end(); }
template<class T, class U>bool isin(T el, U container) { return find(all(container), el) != container.end(); }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T>bool even(T n) { return ! (n & 1); }
template<class T>bool odd(T n) { return n & 1; }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
ll intpow(ll a,ll n){ll p=1;while(n){if(n&1)p*=a;a*=a;n>>=1;}return p;} 
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;

bool isprime(long long n)
{
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;
    for (int i = 3; i*i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

bool isint(long double a) {
    double e = 1e-6;
    if (std::abs(a - std::round(a) < e)) return true;
    else return false;
}

std::vector<long long> eratos(long long n) {
    std::vector<bool> nums(n+1, true);
    nums[0] = nums[1] = false;
    for (long long i = 2; i <= std::sqrt(n)+10; ++i) {
        if (nums[i]) {
            long long j = i * 2;
            while (j <= n) {
                nums[j] = false;
                j += i;
            }
        }
    }
    std::vector<long long> primenums;
    for (long long i = 0; i < n+1; ++i) {
        if (nums[i]) primenums.push_back(i);
    }
    return primenums;
}


template <typename T>
std::vector<std::pair<T, T> > factorint(T n) {
        std::vector<std::pair<T, T> > res;
        for (T i = 2; i*i <= n; ++i) {
                T counter = 0;
                while (n % i == 0) {
                        n /= i;
                        ++counter;
                }
                if (counter != 0) {
                        res.push_back(std::make_pair(i, counter));
                }
        }
        if (n != 1) {
                res.push_back(std::make_pair(n, 1));
        }
        return res;
}

int main()
{
        ll N;
        cin >> N;
        auto v = eratos(100000);
        vll ans;
        
//         rep(idx, 5, inf){
//                 if (len(ans) == N) break;
//                 rep(i, 0, len(ans)) {
//                         rep(j, i+1, len(ans)) {
//                                 rep(k, j+1, len(ans)) {
//                                         rep(l, k+1, len(ans)) {
//                                                 ll total = ans[i] + ans[j] + ans[k] + ans[l] + v[idx];
//                                                 if (isprime(total)) goto e;
//                                         }
//                                 }
//                         }
//                 }
//                 ans.push_back(v[idx]);
// e:
//                 ;
//         }

//         rep(i, 0, N) {
//                 cout << ans[i];
//                 if (i != N-1) cout << ' ';
//                 else cout << endl;
//         } 

        rep(i, 0, inf) {
                if (len(ans) == N) break;
                if (v[i] % 5 == 1) ans.push_back(v[i]);
        }

        rep(i, 0, N) {
                cout << ans[i];
                if (i != N-1) cout << ' ';
                else cout << endl;
        }  
}