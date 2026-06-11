#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<char> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  string ans="Three";
  for(int i=0;i<N;i++){
    if(vec.at(i)=='Y'){
      ans="Four";
    }
  }
  cout<<ans<<endl;
}