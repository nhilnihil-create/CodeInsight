#include <iostream>
#include <set>
using namespace std;
int main(void){
    set< long long > s;
    long long n;
    cin >> n;
    for(long long i=1;i*i<=n;i++){
        if(n%i > 0) continue;
        long long k = i;
        long long m = n/i-1;
        if(k < m) s.insert(m);
        k = n / i;
        m = i-1;
        if(k < m) s.insert(m);
    }
    long long ans = 0;
    for(long long m : s) ans += m;
    cout << ans << endl;
}
