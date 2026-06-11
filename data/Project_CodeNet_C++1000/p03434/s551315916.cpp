#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  
  int max=0,maxnum=0,A=0,B=0,k=0;
  
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(a.at(j)>max){
        max=a.at(j);
        maxnum=j;
      }
    }
    
    if(k%2==0)A+=max;
    else B+=max;
    
    a.at(maxnum)=0;
    max=0;
    maxnum=0;
    k++;
  }
  cout<<A-B<<endl;
}