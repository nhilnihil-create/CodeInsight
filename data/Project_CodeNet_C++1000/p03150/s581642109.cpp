#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i, n) ;for (int i = 0;i < (int)(n);i++)
#define rep2(i, s, n) ;for (int i = s; i < (int)(n);i++)
#define ALL(vec)  (vec).begin(),(vec).end()
#define pi 3.1415926535897932384626433832795
#define MAX_INF 9223372036854775807
#define MIN_INF (922337203685477587+1)
#define sosuu 1000000007

string keyence="keyence";

int main() {
  string S;
  cin >> S;
  bool judge[7];
  rep(i, 7)
    judge[i]=false;
  int N=S.size();
  rep(i, 7){
  if(S[i]==keyence[i]){
  judge[i]=true;
  }
  if(S[N-1-i]==keyence[7-1-i]){
  judge[7-1-i]=true;
  }
    
  
  }
  rep(i, 7){
  if(judge[i]==false){
  cout << "NO" << endl;
  return 0;
  }
  }
  
  cout << "YES" << endl;
  return 0;
}