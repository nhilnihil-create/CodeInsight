/// kazuki08
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define ar array
//#define inf 1000000000
#define mod 1000000007
#define dmp(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define fs first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
    return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
    o<<"{";
    for(const T& v:vc) o<<v<<",";
    o<<"}";
    return o;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



signed main(){
IOS;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

  
  int n;
  cin >> n;
  int x[n+1],y[n+1],h[n+1];
  bool all = true;
  for(int i=1;i<=n;i++){
    cin >> x[i] >> y[i] >> h[i];
    all&=(h[i]==0);
  }

  for(int cx = 0; cx<= 100;cx++){
    for(int cy = 0;cy <= 100;cy++){
      set<int> s;
      bool flag = true;
      for(int i=1;i<=n;i++){
        if(h[i]>0){
          int H = h[i] + abs(cx-x[i]) + abs(cy-y[i]);
          // if(H>0)
          s.insert(H);
          // else flag = false;
        }
      }
      if(s.size()==1){

        int H = *s.begin();
        for(int i=1;i<=n;i++){
          if(!h[i]){
            if(H-abs(cx-x[i])-abs(cy-y[i])>0)flag = false;
          }
        }

        if(flag){
          cout << cx << " " << cy << " " << *s.begin() << endl;
          return 0;
        }
      }
    }
  }

return 0;
}
///....
