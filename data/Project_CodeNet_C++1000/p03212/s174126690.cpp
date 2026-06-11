#include <bits/stdc++.h>
using namespace std;
void C(int i,int N,vector<int> &B,int &j,bool &bo,int &l){
  if(i==0){
    if(B.at(1)>0 && B.at(2)>0 && B.at(3)>0)
      l++;
    return;
  }
  for(int k=0;k<4;k++){
    if(k==0){
      if(j!=0){
        bo=false;
        continue;
      }
    }
    else
      j+=(k*2+1)*pow(10,i-1);
    if(j>N)
      return;
    B.at(k)++;
    C(i-1,N,B,j,bo,l);
    B.at(k)--;
    if(k!=0)
      j-=(k*2+1)*pow(10,i-1);
  }
}

int main(){
  int N;
  cin>>N;
  vector<int> B(4);
  int l=0,j=0;
  bool bo=true;
  C(to_string(N).size(),N,B,j,bo,l);
  cout<<l<<endl;
}