#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std; using ll=long long; using P=pair<int,int>;
const int INF=1e9; template<typename T> using vec=vector<T>;
ll ke(ll x) {ll res=0; while(x>0) res+=x%10, x/=10; return res;}
int main() {
  int n,m; cin>>n>>m;
  vec<int> p={-1,2,5,5,4,5,6,3,7,6};
  vec<char> c={'-','1','2','3','4','5','6','7','8','9'};
  vec<int> v(m);
  for(int i=0;i<m;i++) cin>>v[i];
  vec<string> s(n+1); s[0]="";
  auto pred = [](string a, string b) {if (a.size()!=b.size()) return a.size()<b.size(); else return a<b;};
  for(int i=0;i<=n;i++) {
    string nx=s[i];
    if (i != 0 && s[i].empty()) continue;
    for(int j:v) {
      int mc=i+p[j];
      if (mc<=n) s[mc]=max(s[mc], s[i]+c[j], pred);
    }
    if (i!=0) s[i-1].clear();
  }
  //for(int i=0;i<=n;i++) cout<<i<<": "<<s[i]<<endl;
  cout<<s[n]<<endl;
}