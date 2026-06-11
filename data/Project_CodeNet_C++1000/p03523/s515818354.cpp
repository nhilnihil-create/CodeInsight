#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  string S; cin >> S;
  const string akb = "AKIHABARA";
  
  if(S[0] == 'K') S.insert(S.begin(), 'A');
  else if(S[0] == 'A'){}
  else goto ng;
  if(S[1] != 'K') goto ng;
  if(S[2] != 'I') goto ng;
  if(S[3] != 'H') goto ng;
  if(S[4] == 'B') S.insert(S.begin()+4, 'A');
  else if(S[4] == 'A'){}
  else goto ng;
  if(S[5] != 'B') goto ng;
  if(S[6] == 'R') S.insert(S.begin()+6, 'A');
  else if(S[6] == 'A'){}
  else goto ng;
  if(S[7] != 'R') goto ng;
  if(S[8] != 'A') S.push_back('A');
  
  if(S == akb) cout << "YES" << endl;
  else goto ng;
    
  return 0;
ng:
  cout << "NO" << endl;
  return 0;
}