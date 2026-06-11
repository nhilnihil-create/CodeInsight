#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    long long  ans = 0;
    int count = 0;
    if(k%2 == 1){
        ans = pow(n/k,3);
    }
    else{
        ans = pow(n/k,3);
        for(int i=0; i<INT_MAX; i++){
            if((k*i+k/2) <= n){
                count += 1;
            }
            else{
                break;
            }
        }
        ans += pow(count,3);
    }
    cout << ans << endl;
}