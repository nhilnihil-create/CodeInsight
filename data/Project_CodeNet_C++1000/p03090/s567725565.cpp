#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
using vc = vector<char>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int main(){
  int n;
  cin >> n;
  if(n % 2 == 0){
    cout << n*(n-2)/2 << "\n";
    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        if(i + j == n+1) continue;
        cout << i << " " << j << "\n";
      }
    }
  }else{
    cout << (n-1)*(n-1)/2 << "\n";
    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        if(i + j == n) continue;
        cout << i << " " << j << "\n";
      }
    }
  }
}
