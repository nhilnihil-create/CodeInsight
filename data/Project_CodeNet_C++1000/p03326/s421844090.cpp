#include<bits/stdc++.h>
using ll = long long;
const ll INF_LL = 1000000000000;
#define fir first
#define sec second

int main()
{
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<ll>> A(3,std::vector<ll>(n));
    for(int i = 0; i < n; i++)std::cin >> A[0][i] >> A[1][i] >> A[2][i];

    ll max = -1;
    for(int bit = 0; bit < (1 << 3); bit++){
        auto a = A;
        for(int i = 0; i < 3; i++){
            if(bit & (1 << i)){
                for(int j = 0; j < n; j++)a[i][j] *= -1;
            }
        }
        std::vector<ll> sum(n);
        for(int i = 0; i < n; i++)sum[i] = a[0][i] + a[1][i] + a[2][i];
        std::sort(sum.begin(), sum.end(), std::greater<ll>());
        ll cur = 0;
        for(int i = 0; i < m; i++){
            cur += sum[i];
        }
        max = std::max(cur,max);
    }
    std::cout << max << std::endl;
}
