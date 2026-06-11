#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 15;
int d , g , p[N] , c[N];
int main() {
    abdelrahman010
    cin >> d >> g;
    for(int i = 0;i < d;i++)
        cin >> p[i] >> c[i];
    int ans = 1e9;
    for(int i = 0;i < (1 << d);i++) {
        int cnt = 0 , sum = 0;
        for(int j = 0;j < d;j++)
            if((1 << j) & i)
                cnt += p[j] , sum += (j + 1) * 100 * p[j] + c[j];
        if(sum >= g) {
            ans = min(ans , cnt);
            continue;
        }
        for(int j = d - 1;j >= 0;j--)
            if(!((1 << j) & i)) {
                int tmp = p[j];
                while(sum < g && tmp > 1) {
                    cnt++ , tmp--;
                    sum += (j + 1) * 100;
                }
            }
        if(sum >= g)
            ans = min(ans , cnt);
    }
    cout << ans;
    return 0;
}
