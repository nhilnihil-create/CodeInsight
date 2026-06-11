#include<bits/stdc++.h>
using namespace std;

int main(){
string s;

long long ans  = 1,n,a ;
cin>>n>> a;
if(n==1){cout<<a<<endl;
return 0;
}
for(long long i=2;i<=sqrt(a)+1;i++ ){ 

if(a%i==0){
int cnt=0;
while(a%i==0){
cnt++ ;
a/=i;
 }
cnt/=n;
for(int j=0;j<cnt;j++)ans*=i;
}
}
cout<<ans<<endl;
return 0;
}