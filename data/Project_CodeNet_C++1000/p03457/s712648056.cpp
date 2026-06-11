#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  int n;
  cin >> n;
  int t0=0;
  int x0=0;
  int y0=0;
  for(int i=0;i<n;i++){
    int t,x,y;
    cin >> t >> x >> y;
    t=t-t0;
    x=x-x0;
    y=y-y0;
    int sum=abs(x)+abs(y);
    if(sum>t || sum%2!=t%2){
      cout << "No" << endl;
      return 0;
    }
    t0=t;
    x0=x;
    y0=y;
  }
  cout << "Yes" << endl;
}

