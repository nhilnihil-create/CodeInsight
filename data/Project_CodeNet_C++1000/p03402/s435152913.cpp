#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
#define MOD 1000000007
#define MAX 510000
#define INF 1<<30
#define LINF (ll)1<<62
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    ll a,b; cin >> a >> b;
    ll p = (a-1)/50 + 1;
    ll q = (b-1)/50 + 1;
    ll h = p*2 + q*2;
    ll w = 100;
    cout << h << " " << w << endl;
    ll siro = a-1;
    ll kuro = b-1;
    char s[h][w];
    for(ll i=0; i<p*2; i += 2){
        rep(j,w){
            if(j%2 == 0){
                if(siro > 0){
                    s[i][j] = '.';
                    siro--;
                }else{
                    s[i][j] = '#';
                }
            }else{
                s[i][j] = '#';
            }
        }
        rep(j,w) s[i+1][j] = '#';
    }
    for(ll i=2*p; i<h-1; i+=2){
        rep(j,w) s[i][j] = '.';
        rep(j,w){
            if(j%2 == 0){
                if(kuro > 0){
                    s[i+1][j] = '#';
                    kuro--;
                }else{
                    s[i+1][j] = '.';
                }
            }else{
                s[i+1][j] = '.';
            }
        }
    }
    rep(i,h){
        rep(j,w) cout << s[i][j];
        cout << endl;
    }
}
