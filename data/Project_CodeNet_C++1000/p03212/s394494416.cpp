#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> A = {7, 5, 3};

int N;
vector<int> num; //準七五三数を格納
void dfs(int n, int keta, vector<int> &num){
  if( keta == 10 ) return;
  for( int i = 0; i < 3; i++ ){
    n = n*10 + A[i];
    num.push_back(n);
    dfs(n, keta+1, num);
    n /= 10;
  }
}
signed main() {
  cin >> N;
  dfs(0, 0, num);
  int ans = 0;
  for( int i = 0; i < num.size(); i++ ){
    if( num.at(i) > N ) continue;
    bool s = 0;
    bool f = 0;
    bool t = 0;
    int a = num.at(i);
    while( a > 0 ){
      if( a%10 == 7 ) s = 1;
      if( a%10 == 5 ) f = 1;
      if( a%10 == 3 ) t = 1;
      a /= 10;
    }
    if( s && f && t ) ans++;
  }
  cout << ans << endl;
}
