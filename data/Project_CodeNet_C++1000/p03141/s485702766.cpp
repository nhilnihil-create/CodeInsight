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
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int n;
  cin >> n;
  vector<pair<int,P>> S(n);
  int a = 0;
  int b = 0;
  rep(i,n){
    cin >> S[i].second.first >> S[i].second.second;
    S[i].first = S[i].second.first+S[i].second.second;
    b += S[i].second.second;
  }
  sort(S.rbegin(),S.rend());
  //cout << b << endl;
  for(int i = 0;i < n;i+=2){
    a += S[i].second.first;
    b -= S[i].second.second;
  }
  cout << a - b << endl;
}