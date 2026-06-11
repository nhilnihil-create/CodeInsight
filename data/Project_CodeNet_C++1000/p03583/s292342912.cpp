#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int main(){
    ll N;
    cin >> N;
    for(ll n=1;n<3501;n++){
        for(ll h=1;h<3501;h++){
            if ((4*h*n-N*n-N*h)>0&&(n*N*h)%(4*h*n-N*n-N*h)==0){
                cout << h << " " << n << " " << (n*N*h)/(n*(4*h-N)-N*h);
                return 0;
            }
        }
    }
}