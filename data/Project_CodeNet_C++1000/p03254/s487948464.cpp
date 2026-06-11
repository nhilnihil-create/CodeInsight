#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,x;
  cin>>N>>x;
  int X;
  priority_queue<int,vector<int>,greater<int> > A;
  for(int i=0;i<N;i++){
    cin>>X;
    A.push(X);
  }
  int count=0;
  while(x>=A.top()){
    x-=A.top();
    A.pop();
    count++;
    if(count==N && x>0){
      cout<<count-1;
      return 0;
    }
  }
  cout<<count;
}

  
    
  
