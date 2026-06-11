#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
vector<ll> a(55), p(55);

 
int main(){
  int a,b;
  cin >> a >> b;
  int ans;
  if(b%a==0) ans = a+b;
  else ans = b-a;
  cout << ans << endl;
  return 0;
}
