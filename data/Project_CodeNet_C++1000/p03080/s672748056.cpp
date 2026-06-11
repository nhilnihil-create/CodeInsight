#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n;
  string s;
  cin >> n >> s;
  
  ll r = 0, b = 0;
  for (int i = 0; i < s.size(); i++){
    if (s[i] == 'B')
      b++;
    else
      r++;
  }
  if (r > b)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
    

  
  

  return 0;
}
