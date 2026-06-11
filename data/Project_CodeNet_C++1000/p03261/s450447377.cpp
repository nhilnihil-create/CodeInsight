#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string W1;
  cin>>N>>W1;
  unordered_set<string> A;
  A.insert(W1);
  char c=W1[W1.size()-1];
  for(int i=1;i<N;i++){
    string W;
    cin>>W;
    if(W[0]!=c || A.count(W)){
      cout<<"No"<<endl;
      return 0;
    }
    c=W[W.size()-1];
    A.insert(W);
  }
  cout<<"Yes"<<endl;
}