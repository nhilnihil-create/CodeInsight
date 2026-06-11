#include <bits/stdc++.h>
using namespace std;
 

int main() {
  int N,T,A;
  cin>>N>>T>>A;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  
  vector<int> tem(N);
  for(int i=0;i<N;i++){
    tem.at(i)=1000*T-6*vec.at(i);
  }
  
  int num =0;
  double hi=tem.at(0);
  for(int i=1;i<N;i++){
    if(abs(hi-1000*A)>abs(tem.at(i)-1000*A)){
      hi=tem.at(i);
      num=i;
    }
  }
  cout<<num+1<<endl;
}