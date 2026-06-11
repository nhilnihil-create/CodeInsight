#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5],ans=0,tmp=6,tmp2=10;
    for(int i=0;i<5;i++){
        cin>>a[i];
        if(a[i]%10!=0){
            if(a[i]%10<tmp2){
                tmp=i;
                tmp2=a[i]%10;
            }
        }
    }
    for(int i=0;i<5;i++){
        ans+=a[i];
        if(a[i]%10&&i!=tmp){
            ans+=(10-a[i]%10);
        } 
    }
    cout<<ans<<endl;
    return 0;
}