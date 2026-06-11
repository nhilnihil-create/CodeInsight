#include <iostream>
using namespace std;
typedef long long ll;

ll b[1002][1002];
bool f[1002][1002];

int main()
{
    int n, k;
    cin >> n >> k;
    ll a[1002];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        b[i][i] = a[i];
        for(int j = i + 1; j < n; j++){
            b[i][j] = b[i][j - 1] + a[j];
        }
    }
    ll p[51];
    p[0] = 1;
    for(int i = 1; i <= 50; i++) p[i] = p[i - 1] * 2;
    ll ans = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) f[i][j] = true;
    for(ll l = 50; l >= 0; l--){
        int r = 0;
        for(int i = 0; i < n; i++) for(int j = i; j < n; j++){
            if(f[i][j] && ((b[i][j] >> l) & 1) == 1) r++;
        }
        if(r >= k){
            ans += p[l];
            for(int i = 0; i < n; i++) for(int j = i; j < n; j++){
                if(((b[i][j] >> l) & 1) == 0) f[i][j] = false;
            }
        }
    }
    cout << ans << endl;
}