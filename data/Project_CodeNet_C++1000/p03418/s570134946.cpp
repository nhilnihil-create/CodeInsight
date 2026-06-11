#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    long long ans = 0;
    cin >> n >> k;
    for(int i = k+1;i < n+1;i++){
        ans = ans + (n/i)*(i-k) + max(n%i - k + 1,0ll);
    }
    if(k == 0){
        ans = pow(n,2);
    }
    cout << ans << endl;
}