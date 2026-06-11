#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}




int main() {
  int H,W,N,x,y;
  cin >> H >> W >> N >> y >> x;

  string S,T;
  cin >> S >> T;

  vector<int> cnt(4,0);//L,R,U,D
  char s,t;
  rep(i,N){
    if (i>0) {
      t = T[i-1];
      if (t=='L'&&x+cnt[1]-1>0) cnt[1]--;
      else if (t=='R'&&W>x-cnt[0]+1) cnt[0]--;
      else if (t=='U'&&y+cnt[3]-1>0) cnt[3]--;
      else if (t=='D'&&H>y-cnt[2]+1) cnt[2]--;
    }

    s = S[i];
    if (s=='L') cnt[0]++;
    else if (s=='R') cnt[1]++;
    else if (s=='U') cnt[2]++;
    else cnt[3]++;
    
    // cout << cnt << endl;
    if (x<=cnt[0]||W-x<cnt[1]||y<=cnt[2]||H-y<cnt[3]) {
      cout << "NO\n"; return 0;
    }
  }
  cout << "YES\n";
}