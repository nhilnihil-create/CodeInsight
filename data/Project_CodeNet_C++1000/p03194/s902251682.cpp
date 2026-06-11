#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <math.h>
#include <numeric>
#include <sstream>
#include <queue>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;

vector<int> primes;
map<int, int> factors;

void erathosthenes(int n) {
    bool primeFlags[n+1];
    for (int i = 0; i <= n; i++) primeFlags[i] = true;
    primeFlags[0] = primeFlags[1] = false;
    vector<int> sqrtprimes;
    for (int i = 2; i*i <= n; i++) {
        bool mod0 = false;
        for (int j = 2; j*j <= i; j++) {
            if (i%j == 0) mod0 = true;
        }
        if (!mod0) sqrtprimes.push_back(i);
    }
    for (int i = 0; i < sqrtprimes.size(); i++) {
        for (int j = 2; j <= n; j++) {
            if (j%sqrtprimes[i] == 0) primeFlags[j] = false;
        }
    }
    for (int i = 0; i < sqrtprimes.size(); i++) primeFlags[sqrtprimes[i]] = true;
    for (int i = 1; i <= n; i++) if (primeFlags[i]) primes.push_back(i);
    return;
}

void factoring(ll n) {
    ll m = sqrt(n);
    erathosthenes(m);
    for (int i = 0; i < primes.size(); ++i) {
        while(n%primes[i] == 0){
            factors[primes[i]]++;
            n /= primes[i];
        }
    }
    factors[n]++;
    factors.erase(1);
}

int main(int argc, char const *argv[]) {
    ll n, p;
    cin >> n >> p;
    if (n == 1) {
        cout << p << std::endl;
        return 0;
    }
    if (p == 1) {
        cout << 1 << std::endl;
        return 0;
    }
    factoring(p);
    ll ans = 1;
    for (auto x : factors) {
        long double sisu = x.second/n;
        long double jousu = powl(x.first, sisu);
        ans *= jousu;
    }
    cout << ans << std::endl;
    return 0;
}