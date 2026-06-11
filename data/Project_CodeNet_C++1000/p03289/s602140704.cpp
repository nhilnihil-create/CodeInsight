#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  string S; cin >> S;

  bool flag = (S[0]=='A' && islower(S[1]) && islower(S[S.size()-1]));

  if (flag){
    int cnt = 0;
    for (int i=2;i<S.size()-1;i++){
      if (islower(S[i])) continue;
      else if (S[i]=='C') cnt++;
      else flag = false;
    }  
    
    if (cnt!=1) flag = false;
  }  
  cout << (flag? "AC" : "WA") << endl;
  // cout << (islower(S[S.size()-1])? "AC" : "WA") << endl;


  // cout << fixed << setprecision(6);
  return 0;
}
