#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n; cin >> n;
  ll march[5] = {};
  for(int i=0; i<n; i++){
    string a;
    cin >> a;
    if(a[0]=='M') march[0]++;
    if(a[0]=='A') march[1]++;
    if(a[0]=='R') march[2]++;
    if(a[0]=='C') march[3]++;
    if(a[0]=='H') march[4]++;
  }
  ll ans = 0;
  for(int i=0; i<3; i++){
    for(int j=i+1; j<4; j++){
      for(int k=j+1; k<5; k++){
        ans += march[i]*march[j]*march[k];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
