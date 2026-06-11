#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 100000000000000009
#define int long long
using P = pair<int,int>;
signed main(){
  int k,a,b;
  cin >> k >> a >> b;
  if(k-a > 0){
    if(b-a < 2){
      cout << k + 1 << endl;
    }
    else{
      cout << (b-a)*((k-a+1)/2) + (k-a+1)%2 + a << endl; 
    }
  }
  else{
    cout << k + 1 << endl;
  }
}