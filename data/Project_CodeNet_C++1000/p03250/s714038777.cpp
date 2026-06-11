/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int a,b,c,max;
    cin>>a>>b>>c;
    if(a>=b && a>=c){
        max=a;
        printf("%d",max*10+b+c);
    }
    else if(b>=a && b>=c){
        max=b;
        printf("%d",max*10+a+c);
    }
    else{
        max=c;
        printf("%d",max*10+a+b);
    }
    
    
}
