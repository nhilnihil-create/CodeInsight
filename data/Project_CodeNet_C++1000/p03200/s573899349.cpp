#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  long long w=0LL,sum=0LL;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='W'){
      w++;
      sum+=i;
    }
  }
  if(w==S.size()||w==0LL)
    cout<<"0"<<endl;
  else
    cout<<sum-w*(w-1LL)/2LL<<endl;
}
