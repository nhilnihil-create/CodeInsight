#include<iostream>

using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(b+a<c-1) cout<<a+b+1+b<<endl;
    else cout<<b+c<<endl;
    return 0;
}