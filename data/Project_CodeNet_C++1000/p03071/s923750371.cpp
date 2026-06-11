#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;

    if((a>b)){
        a+=(a-1);
        cout<<a<<endl;
    }
    else if(b>a){
        b+=(b-1);
        cout<<b<<endl;
    }
    else
        cout<<a+b<<endl;
    
    return 0;
}