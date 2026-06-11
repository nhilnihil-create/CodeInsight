#include <iostream>
    #include <boost/multiprecision/cpp_int.hpp>
     
    using namespace std;
     
    typedef long long ll;
    typedef boost::multiprecision::uint128_t uint128_t;
     
    int main() {
        int n; ll x;
        cin >> n >> x;
        ll a[n];
        for(int i=0;i<n;++i) cin >> a[n-1-i];
        for(int i=1;i<n;++i) a[i] += a[i-1];
     
        uint128_t ans = (uint128_t(1) << 90);
        for(int k=1;k<=n;++k) {
            uint128_t tmp_ans = x * ll(k+n);
            tmp_ans += 5LL * a[k-1];
            for(int i=1;i<(n+k-1)/k;++i) {
                tmp_ans += ll(2*i+3) * (a[min(n-1,k*(i+1)-1)] - a[min(n-1, k*i-1)]);
            }
            ans = min(tmp_ans, ans);
        }
        cout << ans << endl;
    }