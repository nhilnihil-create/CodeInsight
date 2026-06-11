#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;
vector<long long int>A;
vector<long long int>cnt(1000050,0);

long long int pow(long long int x,long long int n){
 long long int res;
 if(n==0) return 1;
 res=pow(x*x,n/2);
 if(n%2==1){
  res = res*x;
 }
 return res;
}

int main(void){
 long long int N,P,K,tmp,ans=1;

 cin>>N>>P;
 K=sqrt(P);
 tmp=P;
 for(int i=2; i<=K;){
  if(P%i==0){
   A.push_back(i);
   for(;P%i==0;){
    P/=i;
    cnt[i]++;
   } 
  } 
  if(P==1)break;
  i++;
 }

 for(int i=0;i<A.size(); i++){
  if(cnt[A[i]]/N>0)ans*=pow(A[i],(cnt[A[i]]/N)); 
 }
 if(N==1)cout<<tmp<<endl;
 else cout<<ans<<endl;
 return 0;
}