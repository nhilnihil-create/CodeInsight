#include<iostream>
using namespace std;

int main(){
    int a,b,k;
    cin>>a>>b>>k;
    int gcm;
    int ans[100];
    int cnt=0;
    if(a<b)swap(a,b);
    for(int i=b;i>=1;i--){
        if(a%i==0&&b%i==0){
            gcm=i;
            break;
        }
    }
    for(int i=1;i<=gcm;i++){
        if(gcm%i==0){cnt++;
        ans[cnt]=i;}
    }
    cout<<ans[cnt-k+1]<<endl;
    return 0;
}