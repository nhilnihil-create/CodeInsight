#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a+b==15){
        cout<<'+';
        return 0;
    }
    if(a*b==15){
        cout<<'*';
        return 0;
    }
    cout<<'x';
    return 0;
}