
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int a,b;
    int max;
    cin >> a >> b;
    int add=a+b;
    int sub=a-b;
    int mul=a*b;
    if(add>=sub && add>=mul){
        max=add;
    }
    else if(sub>=add && sub>=mul){
        max=sub;
    }
    else{
        max=mul;
    }
    cout << max;
    
    
}
