#include <bits/stdc++.h>
#include <math.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
ld n , d;
vector<vector<ld>> x(n,vector<ld>(d));

int main(){
    ll n ; cin >> n;

    ll ans = 0;
    
    for(int i=1;i<=1000001;i++){
        if(n%i==0){
            ll m = (n/i) - 1;
            if(m>i) ans+=m;
        }
    }

    cout << ans << endl;
}