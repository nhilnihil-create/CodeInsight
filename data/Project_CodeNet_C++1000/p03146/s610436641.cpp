#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int s;
   cin>>s;
   map<int,int>A;
   int f=s;
   int cnt=1;
   A[s]=1;
   rep(i,1000000){
       if(f%2==1){
           f=3*f+1;
       }
       else{
           f/=2;
       }
       cnt++;
       A[f]++;
       if(A[f]==2){
           break;
       }
   }
   cout<<cnt<<endl;
}