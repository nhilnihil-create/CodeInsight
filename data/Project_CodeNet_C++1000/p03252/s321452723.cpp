#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  string S,T;
  cin >> S;
  cin >> T;
  vector<vector<int> >G(26);
  vector<vector<int> >H(26);
  for(ll i=0;i<S.size();i++){
    /*if(S[i]!=T[i]){
      G[S[i]-'a'].push_back(T[i]-'a');
      G[T[i]-'a'].push_back(S[i]-'a');
    }else{
      G[S[i]-'a'].push_back(T[i]-'a');
      }*/
    G[S[i]-'a'].push_back(T[i]-'a');
    H[T[i]-'a'].push_back(S[i]-'a');
  }
  bool s=true;
  for(int i='a'-'a';i<'z'-'a'+1;i++){
    if(G[i].size()>=0){
      for(ll j=1;j<G[i].size();j++){
	if(G[i][0]!=G[i][j]) s=false;
      }
    }
    if(H[i].size()>=0){
      for(ll j=1;j<H[i].size();j++){
	if(H[i][0]!=H[i][j]) s=false;
      }
    }
  }
  if(s) cout << "Yes" << endl;
  else cout << "No" << endl;
}
