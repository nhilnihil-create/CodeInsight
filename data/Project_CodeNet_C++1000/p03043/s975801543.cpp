#include <bits/stdc++.h>
using namespace std;

int main(){
  
  	long long n, k; cin >> n >> k;
    double res = 0.0;
    for(long long i=1; i<n+1; ++i){
        double tmp = 1.0;
        long long d = i;
        while (d < k) d *= 2, tmp /= 2.0;
        res += tmp;
    }
    res /= n;
    cout << fixed << setprecision(10) << res << endl;
  
    /*long long n, k; cin >> n >> k;
    double res = 0.0;
    for(long long i=1; i<n+1; ++i){
        double tmp = 1.0;
        long long d = i;
        while(i<k){i *= 2; tmp /= 2.0;}
        res += tmp;
    }
    res /= n;
    cout << fixed << setprecision(15) << res << endl;*/
    return 0;
}