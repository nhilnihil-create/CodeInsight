#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD=1e9+7;

//const int MOD=998244353;
const double PI=3.14159265359;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,h,w;
    cin>>n>>h>>w;
    
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans+=(i+h-1<n && j+w-1<n);
        }
    }
    
    cout<<ans;
    
    
    return 0;
}