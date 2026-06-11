#include <bits/stdc++.h>
using namespace std;

int n,Jamesv1[1999],Jamesv2[1999],a,Jamesmax=0,bro=0;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        Jamesv1[a]++;
    }
    for(int a=1;a<=100;a++){
        if(Jamesv1[a]>0){
            bro++;
        }
    }
    cout<<bro<<endl;
}