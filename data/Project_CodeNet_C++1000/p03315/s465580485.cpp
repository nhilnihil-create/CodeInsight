#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int ans  = 0;
  for(int i=0; i<4; i++){
    char c;
    cin >> c;
    if(c=='+') ans++;
    else ans--;
  }
  cout << ans << endl;
  return 0;
}
