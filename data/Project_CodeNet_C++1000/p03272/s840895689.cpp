#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, i;
  cin >> n >> i;
  int ans = n - i + 1;
  cout << ans << endl;
  return 0;
}
