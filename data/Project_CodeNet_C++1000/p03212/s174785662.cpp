#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

ll ans = 0;
ll n;

void dfs(ll cur, int use){
  if (cur > n) return;
  if (use == 0b111) ans++;
  dfs(cur*10+7,use | 0b001);
  dfs(cur*10+5,use | 0b010);
  dfs(cur*10+3,use | 0b100);
}

int main(){
  cin >> n;
  dfs(0,0);
  cout << ans << endl;
  
  return 0; 
}

