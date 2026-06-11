#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;

const int mx=200010;
const ll mod=1e9+7;

int n,a,b;

int main(){
  cin >> n >> a >> b;

  cout << min(a,b) << " " << max(a+b-n,0) << endl;
  return 0;
}