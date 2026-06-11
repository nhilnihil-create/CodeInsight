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
#define MAX 510000
#define INF 1<<30
#define LINF (ll)1<<62
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;

int main(){
    ll n; cin >> n;
    char s[n][n];
    rep(i,n) rep(j,n) cin >> s[i][j];
    ll ans = 0;
    
    rep(b,n){
        bool flag = true;
        rep(i,n-1){
            REP(j,i,n){
                if(s[i%n][(j+b)%n]!=s[j%n][(i+b)%n]){
                    flag = false;
                    break;
                }
                if(!flag) break;
            }
            if(!flag) break;
        }
        if(flag) ans++;
    }
    cout << ans*n << endl;
}