#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<string> vs;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  double ans=0.0;
  rep(i, n){
    double x;
    string u;
    cin >> x >> u;
    if(u=="JPY")ans+=x;
    else ans+=x*380000.0;
  }

  cout << ans << endl;

  return 0;
}