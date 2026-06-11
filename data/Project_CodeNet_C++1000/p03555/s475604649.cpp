#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
  string a, b;
  cin >> a >> b;
  
  int p = 0;
  for(int i = 0; i < 3; i++){
    if(a.at(i) == b.at(2 - i)){
      p++;
    }
  }
  if(p == 3) cout << "YES" << endl;
  else cout << "NO" << endl;
}
