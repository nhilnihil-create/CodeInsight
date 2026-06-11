#include<iostream>
#include<string>
using namespace std;
int main(){

  string S;
  cin>>S;
  string check;
  int num=0;
  int A=0;
  int B=0;
  int ans=0;
  for(int i=0;i<=(int)(S.length()-3);i++){
  
    check=S.substr(i,3);
    //cout<<check<<" ";
    num=stoi(check);
    //cout<<num<<endl;
    A=num-753;
    if(A<0)A*=-1;
    B=ans-753;
    if(B<0)B*=-1;
    if(A<B)ans=num;
  }
  int trueans=ans-753;
  if(trueans<0)trueans*=-1;
  cout<<trueans;
  return 0;
}