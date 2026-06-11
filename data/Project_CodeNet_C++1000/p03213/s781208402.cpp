#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for(ll p = 2; p*p <= n; ++p) {
        if(n%p!=0) continue;
        int num = 0;
        while(n%p==0) {++num; n/=p;}
        res.push_back(make_pair(p, num));
    }
    if(n!=1) res.push_back(make_pair(n,1));
    return res;
}

int N;
map<ll, int> mp;// mp[p] := 素因数分解における素数 p の指数
//約数の個数を mul にするような場合の数
ll f(map<ll, int>::iterator p, ll mul) {
    if(p==mp.end()) {
        if(mul==1) return 1;
        else return 0;
    }
    ll res = 0;
    for(int i = 0; i < p->second+1; ++i) {
        if(mul%(i+1)!=0) continue;
        res+=f(++p, mul/(i+1));
        --p;
    }
    return res;
}

int main() {
    cin >> N;
    for(int i = 2; i<= N; ++i) {
        auto ps = prime_factorize(i);
        for(auto it : ps) mp[it.first] += it.second;
    }
    cout << f(mp.begin(), 75) << endl;
    return 0;
}