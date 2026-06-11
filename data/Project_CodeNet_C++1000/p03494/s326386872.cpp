#include <iostream>
using namespace std;
#define MAX 200
int main(){
    int n,a[MAX],ans=0,flag=0;
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    while(flag==0){
        for(int i=0;i<n;i++){
            if(a[i]%2==0)
                a[i]/=2;
            else{
                flag=1;
                break;
            }
        }
        if(flag==0)
            ans++;
    }
    
    cout<<ans<<endl;
}
