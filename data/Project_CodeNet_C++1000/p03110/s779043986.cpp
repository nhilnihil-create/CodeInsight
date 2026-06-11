#include<bits/stdc++.h>
using namespace std;

int main(){
int n,a;
cin>>n;
string s;
double b,sum=0.0;
while(n--){
  cin>>b>>s;
  if(s=="BTC"){
    sum=sum+b*380000.0;
  }
  sum=sum+b;
}
cout<<sum<<endl;
return 0;
}