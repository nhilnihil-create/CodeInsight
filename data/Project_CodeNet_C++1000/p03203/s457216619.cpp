#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int MAX = 2001;
const int MOD = 1000000007;
 
 



 
signed main(){
    int h,w,n;
    cin>>h>>w>>n;
  
    int x,y,x0[h];
    fill(x0,x0+h,MOD);
    int ans=h;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        x0[x-1]=min(x0[x-1],y-1);
    }
    
    int k=0;
    for(int i=0;i<=h;i++){
        if(i>x0[i]+k){
            ans=i;
            break;
        }
        if(i==x0[i]+k)k++;
    }
   
    cout<<ans;

    return 0;
}