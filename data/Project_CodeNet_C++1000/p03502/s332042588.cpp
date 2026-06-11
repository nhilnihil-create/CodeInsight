#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x=0;
    int dig,num=n;
    while(n){
        dig=n%10;
        x+=dig;
        n/=10;
    }
    if(num%x==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}