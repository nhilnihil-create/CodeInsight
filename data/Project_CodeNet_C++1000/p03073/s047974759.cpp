#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  long long N=S.size();
  long long zero_even=0,zero_odd=0;
  for(int i=0;i<N;i++){
    if(i%2==0 && S.at(i)=='0'){
      zero_even++;
    }  
    else if(i%2==1 && S.at(i)=='0'){
      zero_odd++;
    }  
  }
  long long a_1,a_2;
  a_1=N/2+N%2-zero_even+zero_odd;
  a_2=zero_even+N/2-zero_odd;
  cout<<min(a_1,a_2)<<endl;
}
