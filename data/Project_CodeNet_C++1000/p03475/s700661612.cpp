#include<bits/stdc++.h>
using namespace std;
int n;
int c[500];
int s[500];
int f[500];
int ans[500];
 
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>c[i]>>s[i]>>f[i];
    }
    for(int i=n-2;i>=0;i--){
        int time=s[i]+c[i];
        if(i==n-2){
            ans[i]=time;
            continue;
        }
        for(int j=i+1;j<n-1;j++){
            if(s[j]>=time){
                ans[i]=ans[j];
                break;
            }
            else{
              
              
                if(time%f[j]==0) time=time+c[j];
                else time=(time/f[j]+1)*f[j]+c[j];
                if(j==n-2) ans[i]=time;
            }
        }
    }
  
  
    ans[n-1]=0;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
}