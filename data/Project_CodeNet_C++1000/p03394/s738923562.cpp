#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
ll MOD = 1e9+7;
ll INF = 1e18;
void chmin(ll &a, ll b) { if (a > b) a = b; }
void chmax(ll &a, ll b) { if (a < b) a = b; }

int main(){
  ll i, j;
  ll n;
  ll buf;
  cin >> n;
  if(n == 3)
    cout << "2 5 63" << endl;
  else if(n <= 15002){
    for(i = 1; i <= n - 3; i++){
      cout << i * 2 << " ";
    }
    if((n - 2) % 3 == 1)
      cout << (i + 2) * 2 << " ";
    else
      cout << i * 2 << " ";
    cout << 3 spa 9 << endl;
  }
  else{
    if(n % 2 == 0)
      buf = 15000;
    else
      buf = 14999;
      
    for(i = 1; i <= buf; i++){
      cout << i * 2 << " ";
    }
    
    for(i = 1; i <= n - buf; i++)
      cout << (2 * i - 1) * 3 << " ";
    cout << endl;
  }
    

  

  return 0;
}