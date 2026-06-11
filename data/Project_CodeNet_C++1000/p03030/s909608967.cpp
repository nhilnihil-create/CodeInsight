#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<tuple<string,int,int>> A(N);
  for(int i=0;i<N;i++){
    string s;
    int j;
    cin>>s>>j;
    A[i]=make_tuple(s,100-j,i+1);
  }
  sort(A.begin(),A.end());
  for(int i=0;i<N;i++){
    int j=(get<2>(A[i]));
    cout<<j<<endl;
  }
}