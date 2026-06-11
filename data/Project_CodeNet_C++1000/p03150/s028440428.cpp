#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  string s;
  cin >> s;
  
  int ok = 0;
  for (int i = 0; i < s.size(); i++){
    for (int j = i; j < s.size(); j++){
      if ("keyence" == s.substr(0, i) + s.substr(j))
        ok = 1;
    }
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
    
    
  

  return 0;
}
