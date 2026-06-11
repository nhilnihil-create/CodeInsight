#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<long long> vll, vLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18

ll gcd( ll a, ll b )
{
	ll r, tmp;
 
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  return b;
 
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    ll a,b,c,d;
    REP(i,t){
        cin >> a >> b >> c >> d;
        bool ans = true;
        if(a<b){
            cout << "No\n";
            continue;
        }
        if(b>d){
            cout << "No\n";
            continue;
        }
        if(c>=b){
            cout << "Yes\n";
            continue;
        }
        //a>=b,b<=d,c<b
        ll g = gcd(b,d);
        if(b-g+(a%g)>c) ans = false;
        if(ans) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}