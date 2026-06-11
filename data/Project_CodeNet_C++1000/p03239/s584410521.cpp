#include <bits/stdc++.h>
using namespace std;


int main() {

  int N,T;
  cin>>N>>T;

  int min_wk=10000;
  for(int i=0;i<N;i++){
    int c,t;
    cin>>c>>t;

    if(t<=T)
      min_wk=min(min_wk,c);
  }

  if(min_wk==10000)
    cout<<"TLE"<<endl;
  else
    cout<<min_wk<<endl;

  return 0;
}


