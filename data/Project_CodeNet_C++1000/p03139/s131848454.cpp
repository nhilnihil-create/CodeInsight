#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
  int n,a,b;
  cin >> n >> a >> b;
  cout << min(a,b) << " ";
  if(a+b<=n)cout << 0 << endl;
  else cout << a+b-n << endl;
}