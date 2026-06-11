#include <bits/stdc++.h>
#define _GRIBCXX_DEBUG
using namespace std;

int main(){
  int N;cin>>N;
  pair<pair<string,int>,int> M[N];
  for(int i=0;i<N;i++){
    string S;int P;cin>>S>>P;
    M[i]=make_pair(make_pair(S,-P),i+1);
  }
  //auto m=M.begin();
  sort(M,M+N);
  for(int i=0;i<N;i++) cout<<M[i].second<<endl;
    
}
  