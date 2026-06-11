#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    long long n;
    long long m;
    long long ans=0;
    
    cin >> n >> m;
    
    if(n==1&&m==1){
        
        ans = 1;
        
    } else if(n==1){
        
        ans = m - 2;
        
    } else if(m==1){
        
        ans = n - 2;
        
    } else {
        
        ans = (n-2) * (m-2);
        
    }
    
    cout << ans << endl;
    
    return 0;
    
}