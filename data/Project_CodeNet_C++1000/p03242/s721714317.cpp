#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  string s;
  cin >> s;
  
  for (int i = 0; i < 3; i++){
    if (s[i] == '1')
      cout << 9;
    else
      cout << 1;
  }
  cout << endl;

  return 0;
}
