#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n,a,ans=INT_MAX;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        int z = 0;
        while(a%2 == 0){
            a = a/2;
            z++;
        }
        
        ans = min(ans, z);        
                
    }
    
    cout<< ans <<endl;
}
