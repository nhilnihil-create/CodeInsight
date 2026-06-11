#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=n/10;
    int b=n%1000;
    if(a/100==a%100/10&&a%100/10==a%10)
    cout<<"Yes"<<endl;
    else if(b/100==b%100/10&&b%100/10==b%10)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
}