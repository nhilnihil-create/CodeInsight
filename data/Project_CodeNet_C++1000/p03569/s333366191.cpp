#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
 
int main() {
  string s;
  cin >> s;
  int l=0;int r=s.size()-1;
  int ans = 0;
  while(l<r){
    if(s.at(l) == s.at(r)){
      ++l; --r;
    }else{
      if(s.at(l) != 'x' && s.at(r) != 'x'){
        ans = -1;
        break;
      }else if(s.at(l) == 'x'){
        ans ++; 
        l++;
      }else{
        ans ++; 
        r--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

