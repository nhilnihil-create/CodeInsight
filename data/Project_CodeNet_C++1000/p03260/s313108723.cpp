#include <bits/stdc++.h>

using namespace std;

int verifica(int a,int b){

    if((a*b)%2!=0){
        return 1;
    }else if((a*b*2)%2!=0){
        return 1;
    }else if((a*b*3)%2!=0){
        return 1;
    }

    return 0;
}

int main(){
    int a,b;
    bool c;

    cin>>a>>b;
    
    c = verifica(a,b);

    if(c==1){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}