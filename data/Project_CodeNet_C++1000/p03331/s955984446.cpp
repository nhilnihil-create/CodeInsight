
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

inline int topbit(unsigned long long x){
	return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
	return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){//popcount%2
	return __builtin_parity(x);
}



template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e15;

const ll mod=1e9+7;

int main(){
    ll n;
    cin >> n;
    ll ans=INF;
    for(ll i=1;i<=n/2;i++){
        ll p=i;
        ll q=n-i;
        ll sum_p=0,sum_q=0;
        while(p){
            sum_p+=p%10;
            p/=10;
        }
        while(q){
            sum_q+=q%10;
            q/=10;
        }
        ans=min(ans,sum_p+sum_q);
    }
    cout << ans << endl;
    return 0;
}