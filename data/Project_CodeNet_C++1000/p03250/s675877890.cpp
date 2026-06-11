#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  int ans = a[0] + a[1] + a[2]*10;
  cout << ans << endl;
  return 0;
}
