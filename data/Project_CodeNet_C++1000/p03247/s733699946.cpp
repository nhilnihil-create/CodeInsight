#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

const ll MOD = 1000000007;
const long double EPS = 10e-10;

int main(){
    int n;
    cin >> n;
    ll x[n], y[n], odd_count;
    bool flag = true;
    rep(n){
        cin >> x[i] >> y[i];
        if(!i){
            odd_count = (abs(x[0])+abs(y[0])) % 2;
            continue;
        }
        if((abs(x[i])+abs(y[i])) % 2 != odd_count){
            flag = false;
        }
    }
    if(!flag){
        cout << -1 << endl;
        return 0;
    }

    const int M = 32;
    int m = M+1-(odd_count%2);
    ll d[m];
    cout << m << endl;
    ll dd = (1LL << (M-1));
    rep(m-1){
        cout << dd << " ";
        d[i] = dd;
        dd >>= 1;
    }
    cout << 1 << endl;
    d[m-1] = 1;

    rep(n){
        ll dest_u = x[i]-y[i], dest_v = x[i]+y[i], u = 0, v = 0;

        repp(j, m){
            if(dest_u > u){
                u += d[j];
                if(dest_v > v){
                    v += d[j];
                    putchar('R');
                }else{
                    v -= d[j];
                    putchar('D');
                }
            }else{
                u -= d[j];
                if(dest_v > v){
                    v += d[j];
                    putchar('U');
                }else{
                    v -= d[j];
                    putchar('L');
                }
            }
        }
        putchar('\n');
    }
}
