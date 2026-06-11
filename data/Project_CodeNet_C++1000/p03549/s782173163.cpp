#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N,M;
   cin>>N>>M;
   int ans=(1900*M+100*(N-M))*pow(2,M);
   cout<<ans<<endl;
   return 0;
}