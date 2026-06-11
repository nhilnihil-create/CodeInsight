/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <cstdio>

int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int x,y,z;
    if(a<c){
        x=c-a;
    }
    else{
        x=a-c;
    }
    
    if(a<b){
        y=b-a;
    }
    else{
        y=a-b;
    }
    
    if(b<c){
        z=c-b;
    }
    else{
        z=b-c;
    }
    if(x<=d || (y<=d && z<=d)){
        printf("Yes");
    }
    else{
        printf("No");
    }
}
