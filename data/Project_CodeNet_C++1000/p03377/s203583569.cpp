#include <bits/stdc++.h>
using namespace std;

int main (){
    int a,b,x,sum;
    cin>>a;
    cin>>b;
    cin>>x;
    sum = a+b;
    if(a<=x){
        if(sum>=x){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}