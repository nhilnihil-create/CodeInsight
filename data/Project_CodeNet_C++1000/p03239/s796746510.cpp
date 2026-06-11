#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n, t;
  cin >> n >> t;
  int ans = 10000;
  for(int i=0; i<n; i++){
    int ci, ti;
    cin >> ci >> ti;
    if(ti<=t) ans = min(ans, ci);
  }
  if(ans == 10000){
    cout << "TLE" << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
