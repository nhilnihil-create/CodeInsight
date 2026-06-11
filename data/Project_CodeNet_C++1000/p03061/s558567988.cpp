#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb push_back
#define ld long double
#define f first
#define s second
#define in insert
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e18 + 5;
const int mod = 1e9 + 7;
const int  N = 2e5 + 314;
const long double pi = 3.1415926535897932384626433832795;
int gcd(int x, int y){
    return (x==0?y:gcd(y%x, x));
}
void solve(){
    int n;
    cin>>n;
    vi v(n), suf(n), pref(n);
    for(int i = 0; i < n; i++)cin>>v[i];
    int gc =0;
    for(int i = 0; i < n; i++){
        gc=gcd(gc, v[i]);
        suf[i]=gc;
    }   
    gc=0;
    for(int i = n-1; i >= 0; i--){
        gc=gcd(gc, v[i]);
        pref[i]=gc;
    }   
    int mx = 0;
    mx=max(mx, pref[1]);
    for(int i = 1; i < n-1; i++){
        mx=max(mx,  gcd(suf[i-1], pref[i+1]));
    }
    mx=max(mx, suf[n-2]);
    cout<<mx;
}
signed main(){
    speed;
    int t=1;
    //cin>>t;
    while(t--)solve();
}