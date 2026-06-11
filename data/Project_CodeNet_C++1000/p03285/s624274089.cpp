#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int flag=0;
    for(int i=0;i<=n/4;i++){
        for(int j=0;j<=n/7;j++){
            if(4*i+7*j==n){
                flag=1;
                break;
            }
        }
    }
    if(flag==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}