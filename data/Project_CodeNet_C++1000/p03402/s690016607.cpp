#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11

int main()
{
    int a,b; cin >> a >> b;
    char f[100][100];
    rep(i,100){
        rep(j,100){
            if(i < 50) f[i][j] = '.';
            else f[i][j] = '#';
        }
    }
    for(int i = 0; i < 50; i += 2){
        for(int j = 0; j < 100; j+=2){
            if(b > 1){
                f[i][j] = '#';
                b--;
            }
        }
    }
    for(int i = 51; i < 100; i += 2){
        for(int j = 0; j < 100; j+=2){
            if(a  > 1){
                f[i][j] = '.';
                a--;
            }
        }
    }
    cout << 100 << ' ' << 100 << endl;
    rep(i,100){
        rep(j,100) cout << f[i][j];
        cout << endl;
    }
}