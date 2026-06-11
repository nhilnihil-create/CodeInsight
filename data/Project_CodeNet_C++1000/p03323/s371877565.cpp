#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a, b;
  cin >> a >> b;
  string ans;
  if((a<=8)&&(b<=8)) ans = "Yay!";
  else ans = ":(";
  cout << ans << endl;
  return 0;
}
