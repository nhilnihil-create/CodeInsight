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
  cin >> n >> k;
  vector<int> v(n);

  rep(i, n){
    cin >> v[i];
  }
  int nk=min(n, k);
  int ans=0;
  rep(i, nk+1){
    for(int j=n; j>=n+i-nk; j--){
      int sum=0;
      priority_queue<int, vector<int>, greater<int> > PQ;
      rep(ni, i){
        PQ.push(v[ni]);
        sum+=v[ni];
      }
      for(int nj=j; nj<n; nj++){
        PQ.push(v[nj]);
        sum+=v[nj];
      }
      for(int qi=0; !PQ.empty() && qi<k-i-(n-j); qi++){
        int num=PQ.top();PQ.pop();
        if(num<0){
          sum-=num;
        }
      }
      ans=max(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
