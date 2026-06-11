#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int  a, v, i;
    cin>>i>>a>>v;
    if(a==v || a+i==v || a+i>v || a>v || a+i+1==v || a+i+1>v)
        cout<<a+v<<endl;
    else if (a+i+1<v)
        cout<<a+i+1+a<<endl;
    
    return 0;
}