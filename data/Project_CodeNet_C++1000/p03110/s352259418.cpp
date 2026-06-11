#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  double sum=0;
  for(int i=0;i<N;i++){
  double a; string s;
    cin>>a>>s;
    if(s=="JPY")
       sum+=a;
       else
       sum+=a*380000.0;
  }cout<<setprecision(16)<<sum<<endl;
   return 0;
}