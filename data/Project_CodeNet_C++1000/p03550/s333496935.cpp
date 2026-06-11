typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,z,w;
    std::cin >> n>>z>>w;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    if(n==1){
        std::cout << abs(a[0]-w) << std::endl;
    }else{
        std::cout << max(abs(a[n-1]-w),abs(a[n-2]-a[n-1])) << std::endl;
    }
}