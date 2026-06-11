#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
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
  vector<tuple<int, int, int> > V;
  multiset<int> S;
  rep(i, n){
    int a, b;
    cin >> a >> b;
    V.push_back(make_tuple(a, b, 0));
  }
  rep(i, n){
    int c, d;
    cin >> c >> d;
    V.push_back(make_tuple(c, d, 1));
  }
  ssort(V);
  int vsz=V.size();
  int ans=0;
  rep(i, vsz){
    auto p=V[i];
    if(get<2>(p)==0){
      S.insert(-get<1>(p));
    } else {
      if(S.upper_bound(-get<1>(p))!=S.end()){
        S.erase(S.upper_bound(-get<1>(p)));
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
