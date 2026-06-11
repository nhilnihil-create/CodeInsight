#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n, k;
  cin >> n >>k;
  string s;
  cin >> s;
  vector<int> index;
  rep(i, n){
    if(i==0){
      index.push_back(0);
    } else if(s[i]!=s[i-1]){
      index.push_back(i);
    }
  }
  int isz=index.size();
  int ans=0;
  rep(i, isz){
    int ik;
    if(s[index[i]]=='0'){
      ik=i+2*k;
    } else {
      ik=i+2*k+1;
    }
    if(ik>=isz){
      ans=max(ans, n-index[i]);
    } else {
      ans=max(ans,index[ik]-index[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
