#include <bits/stdc++.h>
using namespace std;

int n,a,b,c,d,z[1999],x,y,bro[1999],j,brosky1=0,brosky2=0,m;

int main(){
    cin>>n>>m>>x;
    for(int j=1;j<=m;j++){
        cin>>z[j];
    }
    for(int i=0;i<=n+1;i++){
        bro[i]=i;
    }
    for(int i=1;i<x;i++){
        for(int j=1;j<=m;j++){
            if(bro[i]==z[j]){
            brosky1++;
            }
        }
    }
    for(int i=x+1;i<n+1;i++){
        for(int j=1;j<=m;j++){
            if(bro[i]==z[j]){
            brosky2++;
            }
        }
    }
    if(brosky1<brosky2){
        cout<<brosky1<<endl;
    }
    else if(brosky1>brosky2){
        cout<<brosky2<<endl;
    }
    else{
        cout<<brosky1<<endl;
    }
}