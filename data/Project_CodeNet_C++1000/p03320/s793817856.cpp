#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //int:2*10**9
typedef long double ld;
typedef pair<ll,ll> P;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define vec2(name,i,j) vector<vector<ll>> name(i,vector<ll>(j))
#define vec2f(name,i,j,k) vector<vector<ll>> name(i,vector<ll>(j,k))
#define vec3(name,i,j,k) vector<vector<vector<ll>>> name(i,vector<vector<ll>>(j,vector<ll>(k)))
#define vec3f(name,i,j,k,l) vector<vector<vector<ll>>> name(i,vector<vector<ll>>(j,vector<ll>(k,l)))
#define vec4(name,i,j,k,l) vector<vector<vector<vector<ll>>>> name(i,vector<vector<vector<ll>>>(j,vector<vector<ll>>(k,vector<ll>(l))))
#define vec4f(name,i,j,k,l,m) vector<vector<vector<vector<ll>>>> name(i,vector<vector<vector<ll>>>(j,vector<vector<ll>>(k,vector<ll>(l,m))))
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000 //14
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

ll powe(ll a, ll b){//aのb乗のmod
    ll ret = 1;
    while(0 < b){
        if((b%2) == 0){
            a = (a*a);
            b >>= 1;
        }
        else{
            ret = (ret*a);
            b--;
        }
    }
    return ret;
}
ll keta(ll x){
    ll ret = 0;
    while(x>0){
        ret+=x%10;
        x/=10;
    }
    return ret;
}

int main(){
    ll k; cin >> k;
    if (k<10){
        FOR(i,1,k) cout << i << endl;
        return 0;
    }
    FOR(i,1,9) cout << i << endl;
    k-=9;
    vector<ll> li;
    FOR(i,10,99) li.pb(i);
    FOR(i,0,13) FOR(j,101,1000) li.pb(j*powe(10,i)-1);
    //REP(i,1000) cout << li[i] << endl;
    ll len = li.size();
    vector<ld> limin(len);
    limin[len-1]=(ld)li[len-1]/keta(li[len-1]);
    FORD(i,len-2,0)limin[i]=min(limin[i+1],(ld)li[i]/keta(li[i]));
    FOR(i,0,len-2){
        if ((ld)li[i]/keta(li[i])<=limin[i+1]){
            cout << li[i] << endl;
            k--;
            if (k==0) return 0;
        }
    }
}