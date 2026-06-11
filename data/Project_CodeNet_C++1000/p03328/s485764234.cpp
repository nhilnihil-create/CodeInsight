#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a, b;
  cin >> a >> b;
  int d = b-a;
  int ans = (1+d)*d/2-b;
  cout << ans << endl;
  return 0;
}
