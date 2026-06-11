#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    double n,m,d; cin >> n >> m >> d;
    double ans;
    if(d == 0){
        ans = 1.0/n;
        ans *= (m-1);
        printf("%.10lf",ans);
    }else{
        ans = (2.0 * (n-d))/(n*n);
        ans *= (m-1);
        printf("%.10lf",ans);
    }
}