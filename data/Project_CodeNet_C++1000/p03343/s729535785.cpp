#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <limits.h>
#include <float.h>
#include <numeric>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1000000007;
ll fact[200200];
ll invfact[200200];

inline ll take_mod(ll a){
    return (a % mod + mod) % mod;
}

inline ll add(ll a, ll b){
    return take_mod(a+b);
}

inline ll sub(ll a, ll b){
    return take_mod(a-b);
}


inline ll mul(ll a, ll b){
    return take_mod(a * b);
}

inline ll pow(ll x, ll n){
    ll res = 1LL;
    while(n > 0){
        if(n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x){
    return pow(x, mod-2);
}

// nは上限
void make_fact(ll n){
    fact[0] = 1;
    ll res = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = res;
        res = mul(res, i+1);
    }
}

// nは上限
void make_invfact(ll n){
    invfact[0] = 1;
    invfact[n] = mod_inv(fact[n]);
    for(int i = n-1; i >= 1; i--){
        invfact[i] = mul(invfact[i + 1], i + 1);
    }
}

ll perm(ll n, ll k){
    return mul(fact[n], invfact[n-k]);
}

ll comb(ll n, ll k){
    return mul(mul(fact[n], invfact[n-k]), invfact[k]);
}

int N, K, Q;
vector<int> a;
int l[2100][2100];
int r[2100][2100];
int order[2100];
vector<int> b;


int main(){
    cin >> N >> K >> Q;
    for(int i = 0; i < N; i++){
        int aa; cin >> aa;
        a.push_back(aa);
    }

    int res = INT32_MAX;
    for(int i = 0; i < N; i++){
        vector<int> total;
        vector<int> tmp;
        for(int j = 0; j < N; j++){
            if(a[j] >= a[i]){
                tmp.push_back(a[j]);
            }
            else{
                int m = tmp.size();
                sort(tmp.begin(), tmp.end());
                for(int k = 0; k < m-K+1; k++){
                    total.push_back(tmp[k]);
                }
                tmp.clear();
            }
        }
        int m = tmp.size();
        sort(tmp.begin(), tmp.end());
        for(int k = 0; k < m-K+1; k++){
            total.push_back(tmp[k]);
        }
        tmp.clear();
        sort(total.begin(), total.end());
        if(total.size() >= Q){
            res = min(res, total[Q-1] - total[0]);
        }
    }

    cout << res << endl;

    return 0;
}