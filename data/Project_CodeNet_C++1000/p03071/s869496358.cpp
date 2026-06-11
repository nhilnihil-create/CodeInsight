#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,maxim;
    cin>>a>>b;
    if(a==b){
        cout<<a*2;
    }
    else{
        maxim=max(a,b);
        cout<<maxim+maxim-1;
    }
}
