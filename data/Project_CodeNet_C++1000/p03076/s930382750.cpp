#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long a[5],min=10,mini=0,ans=0;
    f(i,0,5){
        cin>>a[i];
        if(a[i]%10!=0&&a[i]%10<min){
            min=a[i]%10;
            mini=i;
        }
    }
    f(i,0,5){
        if(i!=mini){
            if(a[i]%10==0){
                ans+=a[i];
            }
            else{
                a[i]/=10;
                ans+=(a[i]+1)*10;
            }
        }
        else{
            ans+=a[mini];
        }
    }
    cout<<ans<<endl;
    return 0;
}
