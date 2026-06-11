#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 1e9;
   
    for(int i=1;i<=n/2+1;i++){
        int a=i,b=n-i;
         int aketa=0;
        int bketa =0;
        while(a>0){
            aketa += a%10;
            a /=10; 
        }
        while(b>0){
            bketa += b%10;
            b /=10; 
        }
        ans = min(ans,aketa+bketa);
    }    
    cout << ans << endl;
 }