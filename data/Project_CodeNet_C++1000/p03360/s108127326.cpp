#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> A(3);
  for(int i=0;i<3;i++){
    cin>>A.at(i);
  }
  int K;
  cin>>K;
  sort(A.begin(),A.end());
  
  A.at(2)=A.at(2)*pow(2,K);
  
  cout<<A.at(0)+A.at(1)+A.at(2)<<endl;
}
