#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define reps(i, m, n) for (int i = m; i < n; i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

bool prime_judge(ll n){
    for (ll i = 2; i*i <= n; i++){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}

vector<ll> divisors_list(ll n){
    vector<ll> res;
    for (ll i = 1; i*i <= n; i++){
        if (n % i == 0){
            res.push_back(i);
            if (n/i != i){
                res.push_back(n/i);
            }
        }
    }
    sort(all(res));
    return res;
}

int main(){
    ll n;
    scanf("%lld", &n);
    int ans = 0;
    for (int i=1; i<=n; i += 2){
      vector<ll> div = divisors_list(i);
      if (div.size() == 8) ans++;
    }
    printf("%d\n", ans);
    return 0;
}