#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2, n3, mayor, suma, auxiliar,maximo,aux2;
    cin>>n1 >> n2>> n3;

    if ( n3>=n2 && n3>=n1 ){
        mayor=n3;
        auxiliar=n1+n2;
        aux2=mayor-1;
        if(auxiliar>=aux2){
            maximo=n3+n2;
        }
        else{
             maximo=auxiliar+1+n2;
        } 
    }
    else{
        maximo=n3+n2;
    }
    
    cout<<maximo;

}