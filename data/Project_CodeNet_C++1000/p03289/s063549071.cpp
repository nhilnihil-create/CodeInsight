#include<bits/stdc++.h>
using namespace std;
#define rep(i,s, n) for(int i = s; i < (int)(n); i++)
#define co(x) cout<<x<<endl
#define SQvec(i,j) vector<vector<int>> data(i, vector<int>(j))
#define mod 1000000000+7
typedef long long int lint;

int main (){
  int N = 0;
  string S,ans = "AC";
  cin >> S;
  
  if(S.at(0) != 'A'){ans = "WA";}
  if(S.at(S.size()-1) == 'C'){ans = "WA";}
  rep(i,2,S.size() - 1){
    if(S[i] == 'C'){N++;}
  }
  if(N != 1){ans = "WA";}
  else{
    rep(i,1,S.size()){
    if(isupper(S[i]) && S[i] != 'C'){ans = "WA";}
    }
  }
  co(ans);
}