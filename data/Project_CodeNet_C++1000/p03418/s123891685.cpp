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
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    ll n,k; cin >> n >> k;
    ll ans = n*n;
    REP(i,1,n+1){
        if(i<=k) ans -= n;
        else{
            ll q = n/i;
            ans -= q*k;
            if(n%i>=k) ans -= max(0LL,k-1);
            else ans -= n%i;
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
}