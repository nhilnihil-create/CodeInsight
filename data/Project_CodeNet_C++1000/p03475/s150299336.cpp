#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    
    ll n, ans=0;
    ll c[509]={};
    ll s[509]={};
    ll f[509]={};
    
    cin >> n;
    
    if(n<=1){
        
        cout << "0" << endl;
        return 0;
        
    }
    
    for(ll i=1; i<=n-1; i++){
        
        cin >> c[i] >> s[i] >> f[i];
        
    }
    
    for(ll i=1; i<=n-1; i++){
        
        ans = 0;
        
        for(ll j=i; j<=n-1; j++){
            
            if(ans<=s[j]){
                
                ans = s[j];
                
            } else if(ans%f[j]==0){
                
                // ans = ans;
                
            } else {
                
                ans = (ans/f[j]+1) * f[j];
                
            }
            
            ans += c[j];
            
        }
        
        cout << ans << endl;
        
    }
    
    cout << "0" << endl;
    
    return 0;
    
}