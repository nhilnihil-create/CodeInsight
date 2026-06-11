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

int main(){
    string s; cin >> s;
    ll n = s.length();
    s='2'+s;
    //cout << s << endl;
    if (s[1]!='1'||s[n]!='0'){
        cout << -1 << endl;
        return 0;
    }
    vector<ll> okl;
    FOR(i,1,n-1) if (s[i]!=s[n-i]){
        cout << -1 << endl;
        return 0;
    }
    FOR(i,1,n/2) if (s[i]=='1') okl.pb(i);
    ll j=1;
    ll ind = 0;
    while(j<=n/2){
        if (j==okl[okl.size()-1]) break;
        if (s[j]=='1'){
            if (ind+1<okl.size()){
                cout << okl[ind] << " " << okl[ind+1] << endl;
                ind++;
            }
        }
        else{
            cout << j << " " << okl[ind] << endl;
        }
        j++;
    }
    cout << j << " " << j+1 << endl;
    FOR(i,j+2,n) cout << j+1 << " " << i << endl;
}