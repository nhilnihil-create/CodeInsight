#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int a, b, k;
  cin >> a >> b >> k;
  int cnt = 0,ans;
  for(int i=b; i>=1; i--){
    if(a%i==0 && b%i==0) cnt++;
    if(cnt==k){
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
