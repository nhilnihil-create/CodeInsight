#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll N,K;
void input()
{
    cin >> N >> K;
}

void solve()
{
    ll a,b,c; 
    ll ans = 0;
    for(a = 1; a <= K; ++a){
        b = c = K - a % K;
        ll a_cnt = 0, b_cnt = 0;
        if((b+c) % K == 0){
            ll tmp_a = a;
            while(a <= N){
                a += K; ++a_cnt;
            }
            while(b <= N){
                b += K; ++b_cnt;
            }
            ans += a_cnt * b_cnt * b_cnt;
            a = tmp_a;
            // cout << a_cnt << " " << b_cnt << endl;
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}