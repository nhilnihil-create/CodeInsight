#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N,A,B;
   cin>>N>>A>>B;
   
   int S=0;
   rep(i,N){
       int num=i+1;
       int sum=0;
       while(num!=0){
           sum+=num%10;
           num/=10;
       }
       if(sum>=A&&sum<=B){
           S+=i+1;
       }
   }
   cout<<S<<endl;
}