#include <bits/stdc++.h>
using namespace std;

int main (){
    int a,b,add,sub,mul,maior;
    cin>>a;
    cin>>b;
    add = a + b;
    sub = a - b;
    mul = a * b;
    if(add<sub){
        maior = sub;
    }else{
        maior = add;
    }
    if(maior<mul){
        cout<<mul<<endl;
    }else{
        cout<<maior<<endl;
    }
    return 0;
}