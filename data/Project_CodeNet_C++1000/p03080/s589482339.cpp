#include <bits/stdc++.h>
using namespace std;

int main() {
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());

  int N;
  cin>>N;

  string S;
  cin>>S;

  int R=0,B=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='R') R++;
    if(S.at(i)=='B') B++;
  }
  
  cout<<(R>B? "Yes":"No")<<endl;
}
