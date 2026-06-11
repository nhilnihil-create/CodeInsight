#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

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
    map<ll,ll> mp;
    rep(i,N){
        auto t = factorize(i+1);
        rep(j,t.size()){
            mp[t[j].first] += t[j].second;
        }
    }
    map<ll,ll> np;
    for(auto& p:mp){
        if(p.second + 1 >= 75){
            np[75]++;
        }
        if(p.second + 1 >= 25){
            np[25]++;
        }
        if(p.second + 1 >= 15){
            np[15]++;
        }
        if(p.second + 1 >= 5){
            np[5]++;
        }
        if(p.second + 1 >= 3){
            np[3]++;
        }
    }
    ll ans = 0;
    ans += np[75];
    ans += np[25]*(np[3]-1);
    ans += np[15]*(np[5]-1);
    ans += ((np[5]*(np[5]-1))/2)*(np[3]-2);
    cout << ans << endl;
}

