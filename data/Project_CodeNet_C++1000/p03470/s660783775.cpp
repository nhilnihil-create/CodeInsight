#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<int> S(N);
  for(int i=0; i<N; i++){
    cin>>S.at(i);
  }
  sort(S.begin(),S.end());
  int Ans=1;
  for(int i=0; i<S.size()-1; i++){
    if(S.at(i)!=S.at(i+1))
      Ans++;
    else continue;
  }
  cout<<Ans<<endl;
}