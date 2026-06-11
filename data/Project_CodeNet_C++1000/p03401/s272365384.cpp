#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    int n;
    int a[100009]={};
    int ans=0;
    long long t=0;
    int m=0;
    
    cin >> n;
    cin >> a[1];
    
    a[0] = 0;
    
    t += abs(a[1]);
    
    for(int i=2; i<=n; i++){
        
        cin >> a[i];
        t += abs(a[i]-a[i-1]);
        
    }
    
    a[n+1] = 0;
    
    t += abs(a[n]);
    
    for(int i=1; i<=n; i++){
        
        m = abs(a[i+1]-a[i]) + abs(a[i]-a[i-1]) - abs(a[i+1]-a[i-1]);
        ans = t - m;
        
        cout << ans << endl;
        
    }
    
    return 0;
    
}