#include<bits/stdc++.h>
using namespace std;
int main(void){
int a,b,c,n=0;
cin>>a>>b>>c;
while(c!=n){
    if(b-a<0)
        break;
    else{
        b-=a;
        n+=1;
    }
}cout<<n<<endl;
return 0;}
