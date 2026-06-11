#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  
  int n=s.size();
  if(s[0]!='1' || s[n-1]!='0'){
    cout << -1 << endl;
    return 0;
  }
  rep(i,n){
    if(i>n-i-2) break;
    if(s[i]!=s[n-i-2]){
      cout << -1 << endl;
      return 0;
    }
  }
  int p=n;
  for(int i=n-1;i>=1;i--){
    cout << p << " " << i << endl;
    if(s[i-1]=='1') p=i;    
  }
  
  return 0;
    

}
