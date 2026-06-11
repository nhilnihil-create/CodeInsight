#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct edge {int to, cost; };
 
int main(){
  int n, a;
  cin >> n >> a;
  string ans = "No";
  for(int i=0; i<=a; i++){
    if(n%500==0) ans = "Yes";
    n--;
  }
  cout << ans << endl;
  return 0;
}
