#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

const int N_MAX = 110;

int n; 
int a[N_MAX];

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];

  double tmp=0;
  rep(i, n){
    tmp+=a[i];
  }
  double av = tmp/n;
  int frm=0;
  rep(i, n){
    if(abs(a[i]-av) < abs(a[frm]-av)){
      frm=i;
    }
  }
  cout << frm << endl;
}
