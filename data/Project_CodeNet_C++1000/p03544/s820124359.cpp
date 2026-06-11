#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  if(N==0){
    cout<<2<<endl;
    return 0;
  }
  if(N==1){
    cout<<1<<endl;
    return 0;
  }
  vector<long long> lucas(N+1,0);
  lucas.at(0)=2;
  lucas.at(1)=1;
  for(int i=2;i<N+1;i++){
    lucas.at(i)=lucas.at(i-1)+lucas.at(i-2);
    if(i==N){
      cout<<lucas.at(i)<<endl;
    }
  }
}


