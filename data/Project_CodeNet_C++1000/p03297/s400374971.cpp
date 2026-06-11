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
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;

ll GCD(ll a, ll b){
    if(b==0) return a;
    else return GCD(b,a%b);
}
 
int main(){
    ll t; cin >> t;
    rep(z,t){
        ll a,b,c,d; cin >> a >> b >> c >> d;
        if(a<b || d<b) puts("No");
        else{
            if(c>=b) puts("Yes");
            else{
                if(a%b > c) puts("No");
                else{
                    ll g;
                    g = GCD(d%b,b);
                    if(b-c <= g) puts("Yes");
                    else puts("No");
                }
            }
        }
    }
}
