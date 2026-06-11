#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N,Q;cin>>N>>Q;
  string s;cin>>s;s='?'+s;s=s+'?';
  vector<pair<char,char>>A(Q);
  for(int i=0;i<Q;i++){
  char t,d;cin>>t>>d;
    pair<char,char>p(t,d);
    A.at(i)=p;
  }int64_t left=0;int64_t right=N+1;
  while(1<right-left){
  int64_t mid=left+(right-left)/2;
    int64_t a=mid;bool x=true;
    for(int i=0;i<Q;i++){
    char t=A.at(i).first;
      char d=A.at(i).second;
      if(s.at(a)==t){
      if(d=='R')a++;
        else a--;
      }if(a==N+1){x=false;break;}
     }if(x)left=mid;
    else right=mid;
   }int64_t left1=0;int64_t right1=N+1;
  while(1<right1-left1){
  int64_t mid=left1+(right1-left1)/2;
    int64_t a=mid;bool x=true;
    for(int i=0;i<Q;i++){
    char t=A.at(i).first;
      char d=A.at(i).second;
      if(s.at(a)==t){
      if(d=='R')a++;
        else a--;
      }if(a==0){x=false;break;}
     }if(x)right1=mid;
    else left1=mid;
   }if(1<=left-right1+1)
    cout<<left-right1+1<<endl;
  else
    cout<<0<<endl;
  return 0;
}