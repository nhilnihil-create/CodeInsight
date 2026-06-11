#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>

using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define RED 3
vector<long long int> A(1000050,0);
long long int N,P;
long long int P1;
long long int ans=1;
long long int cnt=0;

int main(void){
 long long int i=2;
 int check=1;
 cin>>N>>P;
 P1=P;

 if(N==1){
  cout<<P<<endl;
  return 0;
 }

 while(P>1 && i<=sqrt(P1)){
  if(P%i==0){
   cnt++;
   P/=i;
   if(cnt>=N){
    if(cnt>0 && cnt%N==0){
     ans*=i;
    }
   }
  }
  else{
   i++;
   cnt=0;
   check=1;
  }
 }
 
 cout<<ans<<endl; 
 return 0;
}