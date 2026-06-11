#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,T,A;
  cin>>N>>T>>A;
  vector<int> H(N);
  for (int i=0; i<N; i++){
   cin>>H.at(i);
  }
  double dtemp;
  double mini=abs((T-H.at(0)*0.006)-A);
  int mini_i=0;
  for (int i=1; i<N; i++){
    dtemp=abs((T-H.at(i)*0.006)-A);
    if (dtemp<mini){
      mini=dtemp;
      mini_i=i;
    }
  }
  cout<<mini_i+1<<endl;
}
                            