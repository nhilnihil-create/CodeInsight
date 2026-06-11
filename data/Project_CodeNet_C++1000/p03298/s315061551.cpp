#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  string S;
  cin>>N>>S;
  reverse(S.begin()+N,S.end());
  map<pair<string,string>,int> A,B;
  for(int i=0;i<(1<<N);i++){
    bitset<18> C(i);
    string T="",U="";
    for(int j=0;j<N;j++){
      if(C.test(j))
        T+=S[j];
      else
        U+=S[j];
    }
    A[make_pair(T,U)]++;
  }
  for(int i=0;i<(1<<N);i++){
    bitset<18> C(i);
    string T="",U="";
    for(int j=0;j<N;j++){
      if(C.test(j))
        T+=S[j+N];
      else
        U+=S[j+N];
    }
    B[make_pair(T,U)]++;
  }
  int ans=0;
  for(pair<pair<string,string>,int> p:A){
    ans+=p.second*B[p.first];
  }
  cout<<ans<<endl;
}