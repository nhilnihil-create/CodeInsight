#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
#define rep1(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";

int main(){
  ll n; cin >> n;
  string ans;
  if(abs(n)==0) {
    cout << 0;
    return 0;
  }
  while(n!=1){
    if(n>0){
      ans.append(to_string(n%2));
      n=-1*(n/2);
    }else{
      if(abs(n)%2==0){
        ans.append("0");
        n=abs(n)/2;
      }else{
        ans.append("1");
        n=(1+abs(n))/2;
      }
    }
  }
  ans.append("1");
  reverse(ans.begin(),ans.end());
  cout << ans;
  return 0;
}