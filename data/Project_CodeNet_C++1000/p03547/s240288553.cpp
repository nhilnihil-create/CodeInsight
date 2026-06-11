#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> vv;

int main(){
  char x,y;
  cin >> x >> y;
  char ans;
  if(x<y) ans = '<';
  if(x==y) ans = '=';
  if(x>y) ans = '>';
  cout << ans << endl;
}
