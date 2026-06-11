#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  if(N==0){
    cout<<0<<endl;
    return 0;
  }
  vector<int> A(0);
  for(int i=0;N!=0;i++){
    if(N%2==0){
      A.push_back(0);
    }else{
      A.push_back(1);
      if(i%2==0)
        N--;
      else
        N++;
    }
    N/=2;
  }
  for(int i=A.size()-1;i>=0;i--)
    cout<<A[i];
  cout<<endl;
}