#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int k;
  cin >> k;
  int ans = (k/2)*(k-k/2);
  cout << ans << endl;
  return 0;
}
