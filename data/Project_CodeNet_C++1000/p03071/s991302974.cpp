#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,aux;
cin>>a>>b;
if(a==b)
cout<<a*2<<"\n";
else{
aux=max(a,b);
cout<<aux+aux-1<<"\n";
}
    return(0);
}