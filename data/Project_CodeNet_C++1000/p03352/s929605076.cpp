#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int x;
  cin >> x;
  int ans = 0;
  for(int i=0; i<50; i++){
    int tmp = i;
    for(int j=0; j<20; j++){
      tmp *= i;
      if(tmp<=x) ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
