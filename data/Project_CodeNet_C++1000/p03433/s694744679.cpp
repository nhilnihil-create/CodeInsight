#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, A;
  cin>>N>>A;
  string ans;
  if(N%500<=A){
    ans = "Yes";
  }
  else{
    ans = "No";
  }
  cout<<ans<<endl;
}