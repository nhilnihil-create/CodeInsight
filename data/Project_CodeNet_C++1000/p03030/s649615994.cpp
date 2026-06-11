#include <bits/stdc++.h>
using namespace std;

using psin=pair<string,int>;
using psinin=pair<psin,int>;

int main(){
  int N;cin>>N;
  vector<psinin> M;
  for(int i=0;i<N;i++){
    string S;int P;cin>>S>>P;
    psinin X = make_pair(make_pair(S,-P),i+1);
    M.push_back(X);
  }
  //sort(M,M+N);
  sort(M.begin(),M.end());
  for(int i=0;i<N;i++) cout<<M.at(i).second<<endl;
}
  
