#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll d;
  cin >> d;
  
  d -= 22;
  if (d == 0)
    cout << "Christmas Eve Eve Eve" << endl;
  else if (d == 1)
    cout << "Christmas Eve Eve" << endl;
  else if (d == 2)
    cout << "Christmas Eve" << endl;
  else if (d == 3)
    cout << "Christmas" << endl;


  return 0;
}
