#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> p={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  vector<int> q(15);
  for(int i=0;i<15;i++){
    int X=p.at(i);
    while(N>=X){
      q.at(i)+=N/X;
      X*=p.at(i);
    }
  }
  int A=0,B=0,C=0,D=0,E=0;
  for(int i=0;i<15;i++){
    if(q.at(i)>=74){
      E++;
    }
    if(q.at(i)>=24){
      D++;
    }
    if(q.at(i)>=14){
      C++;
    }
    if(q.at(i)>=4){
      B++;
    }
    if(q.at(i)>=2){
      A++;
    }
  }
  cout<<E+B*(B-1)*(A-2)/2+C*(B-1)+D*(A-1)<<endl;
  
}