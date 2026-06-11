#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int y, m, d;
  char a, b;
  cin >> y >> a >> m >> b >> d;
  string ans;
  if(m>4) ans = "TBD";
  else ans = "Heisei";
  cout << ans << endl;
  return 0;
}
