#include<iostream>
int main(){char c[3],d[3];std::cin>>c>>d;puts((c[0]==d[2])*(c[1]==d[1])*(c[2]==d[0])?"YES":"NO");}