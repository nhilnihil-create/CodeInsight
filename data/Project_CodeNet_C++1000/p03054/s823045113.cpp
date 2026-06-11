#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define uni(q) unique(all(q)),q.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    ll h,w,n; cin >> h >> w >> n;
    ll r,c; cin >> r >> c;
    string s,t; cin >> s >> t;
    ll x = c;
    rep(i,n){
        if(s[i]=='R'){
            x++;
        }
        if(x > w){
            puts("NO");
            return 0;
        }
        if(t[i]=='L'){
            x = max(x-1,1LL);
        }
    }
    x = c;
    rep(i,n){
        if(s[i]=='L'){
            x--;
        }
        if(x == 0){
            puts("NO");
            return 0;
        }
        if(t[i]=='R'){
            x = min(x+1,w);
        }
    }
    ll y = r;
    rep(i,n){
        if(s[i]=='D'){
            y++;
        }
        if(y > h){
            puts("NO");
            return 0;
        }
        if(t[i]=='U'){
            y = max(y-1,1LL);
        }
    }
    y = r;
    rep(i,n){
        if(s[i]=='U'){
            y--;
        }
        if(y == 0){
            puts("NO");
            return 0;
        }
        if(t[i]=='D'){
            y = min(y+1,h);
        }
    }
    puts("YES");
}
