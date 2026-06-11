#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;

int main(){
  string c, d;
  cin >> c >> d;
  
  bool ok = true;
  if(c[0] != d[2]) ok = false;
  if(c[2] != d[0]) ok = false;
  if(c[1] != d[1]) ok = false;
  
  if(ok){
    	cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
  return 0;
}
