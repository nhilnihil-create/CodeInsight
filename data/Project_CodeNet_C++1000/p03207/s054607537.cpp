#include<bits/stdc++.h>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
  int N; cin>>N;
  vector<int> K(N);
  for(int i=0; i<N; i++){
    cin>>K.at(i);
  }
  sort(K.begin(),K.end());
  K.at(N-1)/=2;
  int H=0;
  for(int i=0; i<N; i++){
    H+=K.at(i);
  }
  cout<<H<<endl;
}
    
