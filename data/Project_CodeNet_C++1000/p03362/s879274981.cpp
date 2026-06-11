#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

vector<pair<ll,int>> factorize(ll n){
    vector<pair<ll,int>> res;
    for(ll i=2; i*i <=n;i++){
        if(n%i)continue;
        res.emplace_back(i,0);
        while(n % i == 0){
            n /= i;
            res.back().second++;
        }
    }
    if(n != 1)res.emplace_back(n,1);
    return res;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> a;
    for(ll i=2;i<=55555;i++){
        auto v = factorize(i);
        if(v[0].first == i && (i-1)%5 == 0){
            a.push_back(i);
        }
    }
    //cout << a.size() << endl;
    rep(i,N){
        cout << a[i] << (i==N-1?"\n":" ");
    }
}
