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
  int n;
  cin >> n;
  vector<int> a(n);
  priority_queue<int> nega;
  priority_queue<int> posi;
  rep(i, n){
    cin >> a[i];
    if(a[i]>=0){
      posi.push(-a[i]);
    } else {
      nega.push(a[i]);
    }
  }
  int negasz=nega.size();
  ll ans=0;
  int tmp;
  if(negasz%2==1 && !posi.empty()) {
    tmp=nega.top();
    int tmp2=posi.top();
    nega.pop();
    posi.pop();
    if(tmp<tmp2){
      ans-=tmp;
      ans+=tmp2;
    } else {
      ans+=tmp;
      ans-=tmp2;
    }
  } else if(negasz%2==1 && posi.empty()){
    tmp=nega.top();nega.pop();
    ans+=tmp;
  }
  while(!nega.empty()){
    tmp=nega.top();nega.pop();
    ans-=tmp;
  }
  while(!posi.empty()){
    tmp=posi.top();posi.pop();
    ans-=tmp;
  }
  cout << ans << endl;
  return 0;
}
