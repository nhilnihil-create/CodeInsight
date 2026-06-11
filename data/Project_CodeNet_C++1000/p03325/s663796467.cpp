#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  int ans = 0;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    while(true){
      if(a%2!=0) break;
      a /= 2;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
