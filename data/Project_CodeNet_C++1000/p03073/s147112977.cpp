#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int j=0;
  for(int i=0;i<S.size();i++)
    if(S[i]==to_string(i%2)[0])
      j++;
  cout<<min(j,(int)S.size()-j)<<endl;
}