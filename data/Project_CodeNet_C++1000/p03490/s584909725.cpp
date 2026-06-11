#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<bitset>

using namespace std;
typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

int main(){
  string s;
  cin >> s;
  s = s + "T";
  int x, y;
  cin >> x >> y;
  bitset<20000> bx(1), by(1);
  bx = bx << 10000;
  by = by << 10000;
  bool flag = true, first = true;
  int cnt = 0;
  for(char c : s){
    if(c == 'F'){
      cnt += 1;
    }else{
      if(first){
        x -= cnt;
        first = false;
      }else if(flag){
        bx = (bx << cnt) | (bx >> cnt);
      }else{
        by = (by << cnt) | (by >> cnt);
      }
      flag = !flag;
      cnt = 0;
    }
  }
  x += 10000;
  y += 10000;
  //cout << x << " " << y << endl;
  bitset<20000> bu(1);
  if(((bu << x) & bx) != 0 && ((bu << y) & by) != 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
