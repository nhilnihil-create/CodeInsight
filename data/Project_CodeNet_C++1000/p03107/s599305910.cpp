#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int i=0;
  for(char c:S)
    if(c=='0')
      i++;
  cout<<min(i,(int)S.size()-i)*2<<endl;
}