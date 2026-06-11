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
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009
using P = pair<int,int>;
 
int main() {
  #define int long long
  int n;
  cin >> n;
  vint A(n);
  vint B(n);
  rep(i,n) cin >> A[i];
  rep(i,n) cin >> B[i];
  vint up(0);
  int sum = 0;
  int count = 0;
  rep(i,n){
    if(A[i] < B[i]){
      sum += B[i] - A[i];
      count++;
    }
    else if(A[i] > B[i]){
      up.push_back(A[i] - B[i]);
    }
  }
  sort(up.begin(),up.end());
  reverse(up.begin(),up.end());
  rep(i,up.size()){
    if(sum <= 0) break;
    sum -= up[i];
    count++;
  }
  if(sum <= 0)
    cout << count << endl;
  else if(sum > 0)
    cout << -1 << endl;
} 