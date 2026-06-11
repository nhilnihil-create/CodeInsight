#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin>>N;
  vector<int64_t> A(N);
  vector<int64_t> B(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  for(int i=0;i<N;i++){
    cin>>B.at(i);
  }
  int64_t sumA=0;
  int64_t sumB=0;
  for(int i=0;i<N;i++){
    sumA+=A.at(i);
  }
  for(int i=0;i<N;i++){
    sumB+=B.at(i);
  }
  if(sumA<sumB) cout<<-1<<endl;
  else{
    vector<int64_t> C(N);
    for(int i=0;i<N;i++){
      C.at(i)=A.at(i)-B.at(i);
    }
    int64_t M=0;
    int64_t sumM=0;
    for(int i=0;i<N;i++){
      if(C.at(i)<0){
        M++;
        sumM-=C.at(i);
      }
    }
    sort(C.begin(),C.end());
    reverse(C.begin(),C.end());
    for(int i=0;i<N;i++){
      if(sumM==0){
        cout<<M<<endl;
        return 0;
      }
      else if(sumM>C.at(i)){
        M++;
        sumM-=C.at(i);
      }
      else{
        M++;
        cout<<M<<endl;
        return 0;
      }
    }
  }
    
}
  