#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    double n, k; cin >> n >> k;
    double ans = 0;
    
    for(int i=1; i<=n; i++){
        double tmp = 1.0/n; 
        int now = i;
        while(now < k){
            now *= 2;
            tmp /= 2;
        }
        ans += tmp;
    }
    printf("%.12f\n", ans);
    return 0;
}