#include <bits/stdc++.h>
using namespace std;

int main() {
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());

  string S;
  cin>>S;

  int N=0;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='x') N++;
  }
  
  cout<<(N>=8? "NO":"YES")<<endl;
}
