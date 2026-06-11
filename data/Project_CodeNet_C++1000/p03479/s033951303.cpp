#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
    ll x, y;
    cin >> x >> y;
    ll n = y / x;
    int ans = 0;
  
  while(n>=2){
    ans++;
    n/=2;
  }
    cout << ans+1 << endl;
}
