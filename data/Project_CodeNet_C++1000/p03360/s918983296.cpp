#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,k,i,maior,soma;
    cin>>a>>b>>c;
    maior = max({a, b, c});
    soma = (a+b+c) - maior;
    cin>>k;
    
    if(k!=0){
        for(i=0;i<k;i++){
            maior*=2;
        }
        a = soma + maior;
    }else
        soma = a+b+c;

    cout<<a<<endl;
    return 0;
}