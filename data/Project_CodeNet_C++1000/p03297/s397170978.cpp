#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

long long GCD(long long m, long long n){
    if(n == 0) return m;
    else return GCD(n, m % n);
}

signed main(){
    int tt;
    cin >> tt;
    while(tt--){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a < b || d < b){
            cout << "No" << endl;
            continue;
        }
        if(b - c <= 1){
            cout << "Yes" << endl;
            continue;
        }
        ll t = GCD(b, d);
        if(t == 1){
            cout << "No" << endl;
            continue;
        }
        if(a % t <= c && b - c <= t){
            cout << "Yes" << endl;
            continue;
        }else{
            cout << "No" << endl;
            continue;
        }
    }
    return 0;
}