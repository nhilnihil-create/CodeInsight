#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  ll h, w;
  cin >> h >> w;
  if(h==1){
    if(w==1){
      cout << 1 << endl;
    }else{
      cout << w-2 << endl;
    }
    return 0;
  }else if(w==1){
    cout << h-2 << endl;
    return 0;
  }
  ll ans = (h-2)*(w-2);
  cout << ans << endl;
  return 0;
}
