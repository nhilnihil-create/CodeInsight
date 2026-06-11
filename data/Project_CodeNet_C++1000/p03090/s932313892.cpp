#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
constexpr ll MOD = 1000000007;
ll INF = 1001001001001001001;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
    ll N;
    cin >> N;
    vector<pair<ll,ll>> ans;
    ll M = 0;
    if(N % 2 == 1){
        FOR(i,1,N+1){
            FOR(j,i+1,N+1){
                if(i + j != N){
                    ans.emplace_back(i,j);
                    M++;
                }
            }
        }
    }else{
        FOR(i,1,N+1){
            FOR(j,i+1,N+1){
                if(i + j != N + 1){
                    ans.emplace_back(i,j);
                    M++;
                }
            }
        }
    }
    cout << M << endl;
    rep(i,M) cout << ans[i].first << ' ' << ans[i].second << endl;
}
