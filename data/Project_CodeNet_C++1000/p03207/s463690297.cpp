#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
  cin>>A[i];
  }
  sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    int a=0;
    a+=A[0]/2;
    for(int i=1;i<N;i++){
    a+=A[i];
    }
  cout<<a<<endl;

}
