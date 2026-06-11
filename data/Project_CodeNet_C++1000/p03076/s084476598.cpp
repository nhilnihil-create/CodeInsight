#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int a[5];
    int x=0,tmp=0;
    int sum=0;
    for(int i=0;i<5;i++){
        cin>>a[i];
        if(a[i]%10==0){
            sum+=a[i];
        }else{
            sum+=(a[i]/10+1)*10;
            x=10-a[i]%10;
        }
        tmp=max(x,tmp);
    }
    cout<<sum-tmp<<endl;
    return 0;
}