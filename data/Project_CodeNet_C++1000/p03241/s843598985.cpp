#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


ll h,w;
vector<string> v(50);

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // push its partner
            if (N/i != i) res.push_back(N/i);
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main(){

    ll n,m; cin >> n >> m;
    float nn = n, mm = m;
    vector<ll> a = enum_divisors(m);

    for(int i = a.size()-1; i >= 0; i --){
        if(a[i] - m/n < EPS ){
            cout << a[i];
            return 0;
        }
    }

}