#include<bits/stdc++.h>
using namespace std;
int a,b,c;

int main(){
    cin>>a>>b>>c;
    if(a-b==0){
        cout<<c;
    }
    else if(a-c==0){
        cout<<b;
    }
    else{
        cout<<a;
    }
}