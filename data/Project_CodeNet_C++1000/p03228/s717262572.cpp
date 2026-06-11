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
#define LINF 1LL<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;
const int mod = 1e9 + 7;

int main(){
    ll a,b,k; cin >> a >> b >> k;
    rep(i,k){
        if(i%2==0){
            b += a/2;
            a = a/2;
        }else{
            a += b/2;
            b = b/2;
        }
    }
    cout << a << " " << b << endl;
}