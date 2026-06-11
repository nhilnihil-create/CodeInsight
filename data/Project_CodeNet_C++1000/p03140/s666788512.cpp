#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
ll MOD = 1e9+7;
void chmin(long long &a, long long b) { if (a > b) a = b; }

int main(){
  ll i , j;
  ll n;
  string a, b, c;
  cin >> n >> a >> b >> c;
  ll result = 0;
  ll buf;
  for(i = 0; i < n; i++){
    buf = (a[i] == b[i]) + (b[i] == c[i]) + (c[i] == a[i]);
    if(buf == 1)
      result++;
    else if(buf == 0)
      result += 2;
  }
  cout << result << endl;

  return 0;
}