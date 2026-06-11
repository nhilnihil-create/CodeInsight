#include<bits/stdc++.h>

using namespace std;

int a, b;

int main(){

    cin>>a>>b;

    int t=0;

    for(int i=0;i<2;i++){
        if(a>=b){
            t+=a;
            a--;
        }
        else{
            t+=b;
            b--;
        }
    }

    cout<<t;

    return 0;
}