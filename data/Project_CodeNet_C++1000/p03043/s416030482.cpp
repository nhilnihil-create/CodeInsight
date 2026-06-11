#include<bits/stdc++.h>
using namespace std;

int main(){
    double N, K, ans = 0;
    cin >> N >> K;
    for(double n = 1; n <= N; ++n){
        double buf = 0, tmp = n;
        while(tmp < K){
            tmp *= 2;
            ++buf;
        }
        ans += 1/N * pow(1./2., buf);
    }
    cout << setprecision(16) << ans << endl;
    return 0;
}