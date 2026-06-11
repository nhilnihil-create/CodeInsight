#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n;
  cin >> n;
  int ans = 0, ma = 0;
  for(int i=0; i<n; i++){
    int p;
    cin >> p;
    ma = max(ma, p);
    ans += p;
  }
  ans -= ma/2;
  cout << ans << endl;
  return 0;
}
