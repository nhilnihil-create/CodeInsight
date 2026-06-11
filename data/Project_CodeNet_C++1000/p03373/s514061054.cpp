#include <bits/stdc++.h>
using namespace std;
int main(){
  long long A,B,C,X,Y,ans=0,temp=0;
  cin >>A>>B>>C>>X>>Y;
  X*=2,Y*=2;
  //全てABピザ
  long long Z=max(X,Y);
  ans=Z*C;
  //X<YでAをすべてABピザ
  if(X<Y){
    temp+=X*C;
    temp+=(Y-X)/2*B;
    if((Y-X)%2!=0) temp+=B;
    ans=min(ans,temp);
  }
  else{
    temp+=Y*C;
    temp+=(X-Y)/2*A;
    if((X-Y)%2!=0) temp+=A;
    ans=min(ans,temp);
  }
  //すべてAorBピザ
  temp=X/2*A+Y/2*B;
  if(X%2!=0) temp+=A;
  if(X%2!=0) temp+=B;
  ans=min(ans,temp);
  if(X%2!=0) temp-=A;
  if(X%2!=0) temp-=B;
  temp+=C;
  ans=min(ans,temp);
  cout <<ans <<endl; 
}