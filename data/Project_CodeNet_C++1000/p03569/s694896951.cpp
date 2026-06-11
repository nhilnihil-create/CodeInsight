#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  string s;
  cin >> s;
  bool flag = true;
  int left = 0;
  int right = s.size()-1;
  int x = 0;
  while(left != right){
    if(s[left] == 'x' && s[right] != 'x'){
      left++;
      x++;
    }
    else if(s[left] != 'x' && s[right] == 'x'){
      right--;
      x++;
    }
    else if(s[left] == s[right]){
      left++;
      if(left == right) break;
      right--;
    }
    else{
      flag = false;
      break;
    }
  }
  if(flag) cout << x << endl;
  else cout << -1 << endl;
}