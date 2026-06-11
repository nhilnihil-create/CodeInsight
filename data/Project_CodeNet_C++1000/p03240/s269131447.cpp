#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;


int main(){
  int N; cin >> N;
  int x[N], y[N], h[N]; rep(i,N) cin >> x[i] >> y[i] >> h[i];

  for (int cx=0;cx<=100;cx++){
    for (int cy=0;cy<=100;cy++){
      int idx;
      rep(i,N) if (h[i]!=0) {
        idx = i;
        break;
      } 
      int H = h[idx] + abs(cx-x[idx]) + abs(cy-y[idx]);
      bool ok = true;
      rep(i,N){
        int h_tmp = max(H - abs(cx-x[i]) - abs(cy-y[i]),0);
        if (h[i]!=h_tmp) ok = false;
      }
      if (ok) {
        cout << cx << " " << cy << " " << H << endl;
        return 0;
      }
    }
  }




  // cout << fixed << setprecision(10);
  
  return 0;
}
