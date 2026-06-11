#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
const int INF = 1e18;

signed main(){
    int n; cin >> n;
    vector<pair<int,int>> food(n);
    int A[n],B[n];
    REP(i,n){
        int a,b; cin >> a >> b;
        food[i] = {a+b,i};
        A[i] = a;
        B[i] = b;
    }
    sort(rall(food));
    int ans = 0;
    REP(i,n){
        if(i%2 == 0) ans += A[food[i].second];
        else ans -= B[food[i].second];
    }
    cout << ans << endl;
}