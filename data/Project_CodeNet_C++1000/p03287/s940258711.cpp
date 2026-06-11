#include<bits/stdc++.h>
#define fir first
#define sec second
using ll = long long;


int main()
{
    int n,m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        a[i] %= m;
    }
    std::vector<ll> sum(n + 1);
    for(int i = 0; i < n; i++)sum[i + 1] = sum[i] + a[i];
    std::map<ll,ll> mp;
    for(int i = 0; i <= n; i++)mp[sum[i] % m]++;
    ll cnt = 0;
    for(auto i :mp){
        cnt += (i.sec * (i.sec - 1)) / 2;
    }
    std::cout << cnt << std::endl;
    
}
