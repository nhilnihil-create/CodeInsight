#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    ll n, x;
    cin >> n >> x;
    ll a;
    ll GCD=0;
    rep(i, n)
    {
        cin >> a;
        if(GCD == 0){
            GCD = abs(a - x);
            continue;
        }
        GCD = __gcd(GCD, abs(a - x));
    }
    cout << GCD << endl;
    return 0;
}