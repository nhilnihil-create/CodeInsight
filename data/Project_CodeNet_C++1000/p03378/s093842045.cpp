#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,X;cin>>N>>M>>X;
 // vector<int> A(M);
  int left=0;
  int right=0;
  for(int i=0;i<M;i++){
 //   cin>>A.at(i);
    int A;cin>>A;
    if(A<X) left++;
    else right++;
  }
  cout<<min(left,right)<<endl;
}
