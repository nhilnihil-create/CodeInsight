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

int countAB(string s){
  int N = s.size();
  int cnt = 0;
  rep(i,N-1){
    if (s.substr(i,2)=="AB") cnt++;
  }
  return cnt;
}

int main(){
  int N; cin >> N;
  int A=0, B=0, BA=0;
  int ans = 0;
  rep(i,N){
    string s;
    cin >> s;
    ans += countAB(s);
    if (s[0]=='B' && s[s.size()-1]=='A') BA++;
    else if (s[0]=='B') B++;
    else if (s[s.size()-1]=='A') A++;
  }
  
  if (A==0 && B==0) ans += max(0,BA-1);
  else ans += min(A,B) + BA;

  cout << ans << endl;
  






  // cout << fixed << setprecision(10);
  
  return 0;
}
