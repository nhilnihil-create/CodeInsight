#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k; cin >> n >> k;
    
    long double res = 0;
    for(long long  i=1; i<n+1; ++i){
        long long  d = i;
        long double x = 1.0;
        
        while(d<k){
            d *= 2; x /= 2;
        }
        res += x;
    }
    
    res /= n;
    cout << fixed << setprecision(15) << res << endl;
    return 0;
}