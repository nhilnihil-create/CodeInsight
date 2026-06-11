#include<bits/stdc++.h>
using namespace std;
main(){
int i,j,k,l,m;
while(cin>>m){
    int x[m];
    for(i=0;i<m;i++)cin>>x[i];
    sort(x,x+i); k=0;
     for(i=0;i<m;i++) {k+=x[i];
     k--;}
     if(k<0)k=0;
    cout<<k<<endl;
} return 0;
}