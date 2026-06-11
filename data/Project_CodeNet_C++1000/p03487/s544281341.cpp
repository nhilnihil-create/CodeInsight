#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    int ans = 0;
    cin >> n;
    map<ll,int> mli;
    rep(i,n){
        ll x;
        cin >> x;
        mli[x]++;
    }
    for(auto u : mli){
        if(u.first != u.second){
            if(u.first < u.second) ans += u.second - u.first;
            else ans += u.second;
        }
    }
    cout << ans << endl;
    return 0;
}