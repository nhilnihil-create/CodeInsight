#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int>A(3);
  int K;
  cin>>A.at(0)>>A.at(1)>>A.at(2)>>K;
  sort(A.begin(),A.end());
  for(int i=0;i<K;i++){
    A.at(2)=2*A.at(2);
  }
  cout<<A.at(0)+A.at(1)+A.at(2)<<endl;
}

  