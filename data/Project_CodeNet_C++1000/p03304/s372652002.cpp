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

int main(){
    ld n,m,d;
    cin >> n >> m >> d;
    ld ans;
    if(d){
        ans = 2.0*(n-d)*(m-1)/(n*n);
    }else{
        ans = (m-1)/n;                
    }
    cout << setprecision(15) << ans << endl;
}