#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>pppp(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}
 
int main() {
 int N;
 cin>>N;
 int A=N/1000;
 int B=N/100%10;
 int C=N/10%10;
 int D=N%10;
 char a,b,c;
 for(int i=0;i<=1;i++){ 
   for(int j=0;j<=1;j++){
     for(int k=0;k<=1;k++){
       int sum=A;
       if(i==1){a='+';sum+=B;}
       if(i==0){a='-';sum-=B;}
       if(j==1){b='+';sum+=C;}
       if(j==0){b='-';sum-=C;}
       if(k==1){c='+';sum+=D;}
       if(k==0){c='-';sum-=D;}
       if(sum==7){cout<<A<<a<<B<<b<<C<<c<<D<<"=7"<<endl;return 0;}
     }
   }
 }
 
 return 0;
}