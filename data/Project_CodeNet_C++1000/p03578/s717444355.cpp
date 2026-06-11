#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  priority_queue<int>A;
  for(int i=0;i<N;i++){
    int a; cin>>a;
    A.push(a);
  }
  int M; cin>>M;
  priority_queue<int>B;
  for(int i=0;i<M;i++){
    int b; cin>>b;
    B.push(b);
  }
  while(!A.empty()){
    if(A.top()==B.top())B.pop();
    A.pop();
    if(B.empty()){cout<<"YES"<<endl;return 0;}
  }
  cout<<"NO"<<endl;
}