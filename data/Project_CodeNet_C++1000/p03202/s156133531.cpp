#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

vec a(0);
bool ok(ll kind){
    map<ll,ll> st;
    ll last = 0;
    st[0] = 0;
    //rep(i,N) st[a[i]] = 0;
    rep(i,N){
        if(a[i] > 1e+6) continue;
        if(last > a[i]){
            for(auto ite = st.rbegin(); ite->fi > a[i] && ite != st.rend(); ++ite) st.erase(ite->fi);//ite->se = 0;
            ++st[a[i]];
        }else if(last == a[i]){
            ++st[a[i]];
        }
        ll see = a[i];
        while(st[see] >= kind && see != 0) {
            st.erase(see);
            --see;
            ++st[see];
        }
        if(see == 0) {
            st.clear();
            return false;
        }
        last = a[i];
    }
    st.clear();
    return true;
}
int main(){
    cin>>N;
    rep(i,N) cin>>A, a.push_back(A);
    ll lb = 0, ub = 2e+5;
    while(ub - lb > 1){
        ll cen = (ub + lb)/2;
        (ok(cen) ? ub : lb) = cen;
        //cout<<cen<<endl;
    }
    cout<<ub<<endl;
}
