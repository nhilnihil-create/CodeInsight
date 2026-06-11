#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
constexpr ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(12);
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    REP(i,N)cin >> A[i] >> B[i];
    ll ans = 0;
    bool equal = 1;
    ll mn = mod;
    ll sum = 0;
    REP(i,N){
        if(A[i]!=B[i]){
            equal = 0;
            if(A[i] < B[i]){
                ans += B[i];
            }else{
                chmin(mn,B[i]);
            }
        }else{
            ans += B[i];
        }
        sum += B[i];
    }
    cout << (equal ? 0 : sum - mn) << "\n";
}