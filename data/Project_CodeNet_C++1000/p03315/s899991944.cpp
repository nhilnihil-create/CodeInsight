#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int N=0;
  for(char c:S){
    if(c=='+')
      N++;
    else
      N--;
  }
  cout<<N<<endl;
}