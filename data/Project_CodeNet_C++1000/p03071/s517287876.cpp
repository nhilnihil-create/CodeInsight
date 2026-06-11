#include <bits/stdc++.h>
using namespace std;
int main(){
int suma;
int a, b;
cin>>a>>b;
if(a==b){
    suma=a+b;
}else if(a>b){
    suma=a+a-1;
}else suma =b+b-1;
cout <<suma;
    return 0;
}