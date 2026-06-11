#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11


int main()
{
    int n; cin >> n;
    int ans = 0;
    rep(i,n+1){
        if(i % 2 == 0) continue;
        int cnt = 0;
        for(int j = 1; j*j <= i; j++){
            if(i % j == 0){
                if(j * j == i) cnt++;
                else cnt += 2;
            }
        }
        if(cnt == 8) ans++;
    }
    cout << ans << endl;
}