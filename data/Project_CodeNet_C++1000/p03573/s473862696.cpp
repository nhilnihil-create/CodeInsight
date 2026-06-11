
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a==b && a!=c && b!=c){
        printf("%d",c);
    }
    if(b==c && a!=b && a!=c){
        printf("%d",a);
    }
    if(c==a && a!=b && c!=b){
        printf("%d",b);
    }
    
    
}
