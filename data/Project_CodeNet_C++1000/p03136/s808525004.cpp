#include<bits/stdc++.h>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
  int N; cin>>N;
  vector<int> S(N);
  for(int i=0; i<N; i++){
    cin>>S.at(i);
  }
  sort(S.begin(),S.end());
  int A=0;
  for(int i=0; i<N-1; i++){
    A+=S.at(i);
  }
  if(A>S.at(N-1))
    cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
