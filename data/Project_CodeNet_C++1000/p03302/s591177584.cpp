#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a+b==15){puts("+");return 0;}
    if(a*b==15){puts("*");return 0;}
    puts("x");
    return 0;
}