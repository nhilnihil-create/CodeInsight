#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int a,b;
    cin>>a>>b;
    int ans[16]={0};
    int mx=max(a,b);
    for(int i=0;i<16;i++){
        if(i%2==0 && mx>0){
            ans[i]=1;
            mx--;
        }    
    }
    int count=0;
    for(int i=0;i<16;i++){
        if(ans[i]==0)count++;
    }
    if(count>=b && mx==0)cout<<"Yay!";
    else cout<<":(";
}
