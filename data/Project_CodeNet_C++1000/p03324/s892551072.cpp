#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int d, n;
  cin >> d >> n;
  if(n==100) n++;
  int ans;
  if(d==0) ans = n;
  else if(d==1) ans = n*100;
  else ans = n*10000;
  cout << ans << endl;
  return 0;
}
