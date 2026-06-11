#include<bits/stdc++.h>
using namespace std;
int main(void){
int n,x[3];cin>>n;
for(int i=0;i<3;i++){
    x[2-i]=n%10;
    n=n/10;
}
for(int i=0;i<3;i++){
    if(x[i]==1)
        x[i]=9;
    else
        x[i]=1;
}
cout<<x[0]*100+x[1]*10+x[2]<<endl;
return 0;}
