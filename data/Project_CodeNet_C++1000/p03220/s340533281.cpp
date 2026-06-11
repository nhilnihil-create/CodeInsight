#include <bits/stdc++.h>
using namespace std;
 

int main() {
  int N,T,A;
  cin>>N>>T>>A;
  
  vector<int> meruru(N);
  for(int i=0;i<N;i++){
    cin>>meruru.at(i);
  }
  
  vector<int> mimi(N);
  for(int i=0;i<N;i++){
    mimi.at(i)=1000*T-6*meruru.at(i);
  }
  
  int totori =0;
  int rorona=mimi.at(0);
  for(int i=1;i<N;i++){
    if(abs(rorona-1000*A)>abs(mimi.at(i)-1000*A)){
      rorona=mimi.at(i);
      totori=i;
    }
  }
  cout<<totori+1<<endl;
}
