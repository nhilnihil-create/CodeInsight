#include <bits/stdc++.h>
using namespace std;



int main(){
  string S;
  cin>>S;
  int64_t sum=0;
  int64_t kaz=0;
  for(int i=0;i<(int64_t)S.size();i++){
    if(S.at(i)=='W'){
      sum+=i;
      kaz++;
    }
  }
  int64_t N=kaz-1;
  cout<<sum-(N+1)*N/2<<endl;
  
}