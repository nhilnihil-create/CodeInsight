#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  vector<ll> a(3);
  for (int i = 0; i < 3; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  
  if (a[0] == a[2])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
    
  

  return 0;
}
