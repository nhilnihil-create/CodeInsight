#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
ll MOD = 1e9+7;

int main(){
  ll i, j;
  ll a, b;
  bool judge = true;
  vector<ll> count(4, 0);
  for(i = 0; i < 3; i++){
    cin >> a >> b;
    count[a - 1]++;
    count[b - 1]++;
  }
  for(i = 0; i < 4; i++)
    if(count[i] != 1 && count[i] != 2)
      judge = false;
  
  if(judge)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}