#include <iostream>
using namespace std;
int main(void){
    int n, k;
    long long ans = 0;
    cin >> n >> k;
    
    for(int b = k + 1; b <= n; b++){
        long long v = (n - b + 1) / b;
        ans += (v+1) * (b-k);
        if(b*(v+1)+k <= n){
            ans += n - b*(v+1)-k + 1;
        }
    }
    if(k == 0) ans -= n;
    cout << ans << endl;
}
