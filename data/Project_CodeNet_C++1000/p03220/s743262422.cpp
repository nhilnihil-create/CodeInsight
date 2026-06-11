#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rep2(i,n) for(int i=0;i<=n;i++)
#define repr(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()
#define P pair<long long,long long>
#define double long double
#define INF 1e10
#define MOD 1e9+7
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
signed main(){
  int a,b,c;
  cin>>a>>b>>c;
  vector<double> d(a),e(a);
  rep(i,a)
    cin>>d[i];
  rep(i,a){
    e[i]=b-0.006*d[i];
  }
  double f=1e9,w;
  rep(i,a){
    if(f>abs(e[i]-c)){
    f=abs(e[i]-c);
      w=i+1;
    }
   
      }
  cout<<w<<endl;
}
