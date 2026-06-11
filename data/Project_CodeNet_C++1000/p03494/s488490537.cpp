#include <bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i =0;i<N;i++){
   cin>>A.at(i);
}
  bool a =false;
  int sum =0;
  for(int i =0;i<1000000000;i++){
    for(int j=0;j<N;j++){
      if(A.at(j)%2!=0){
        a = true;
        break;
      }else{
        A.at(j)/=2;
    }
    }
    if(a){
      break;
    }
  sum++;
  }
  cout<<sum<<endl;
}