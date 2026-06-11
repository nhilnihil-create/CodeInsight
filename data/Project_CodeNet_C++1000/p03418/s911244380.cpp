#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    long long n, k;
    long long ans=0;
    long long tmp=0;
    
    cin >> n >> k;
    
    if(k==0){
        
        cout << n*n << endl;
        
        return 0;
        
    }
    
    ans += (n-k) * (n-k+1) / 2;
    
    for(int i=1; i<=n; i++){
        
        tmp = n - i + 1;
        tmp /= i;
        tmp *= max(0LL, i-k);
        tmp += max(0LL, (n-i+1)%i-k);
        ans += tmp;
        
    }
    
    cout << ans << endl;
    
    return 0;
    
}