#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int a[5], ans=0;
  int m = 10;
  for(int i=0; i<5; i++){
    cin >> a[i];
    if(a[i]%10!=0){
      m = min(m, a[i]%10);
      a[i] /= 10;
      a[i]++;
      a[i] *= 10;
    }
    ans += a[i];
  }
  ans -= (10-m);
  cout << ans << endl;
  return 0;
}
