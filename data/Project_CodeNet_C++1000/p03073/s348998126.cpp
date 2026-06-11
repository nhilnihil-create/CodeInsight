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
  
  // S[0]=='0'
  int cnt_ev = 0;
  rep(i,S.size()) {
    if (i%2==0 && S[i]=='1') cnt_ev++;
    else if (i%2==1 && S[i]=='0') cnt_ev++;
  }

  // S[0]=='1'
  int cnt_od = 0;
  rep(i,S.size()) {
    if (i%2==0 && S[i]=='0') cnt_od++;
    else if (i%2==1 && S[i]=='1') cnt_od++;
  }

  cout << min(cnt_ev, cnt_od) << endl;



  // cout << fixed << setprecision(6);
  return 0;
}
