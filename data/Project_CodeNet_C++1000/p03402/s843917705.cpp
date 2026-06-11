#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for(int i = 0;i < (n);++i)

#define endl '\n'
#define pb emplace_back
#define mkp make_pair
#define p_q priority_queue
#define INF 2000000000
#define PI 3.1415926
#define coutdb cout << fixed << setprecision(10)

const int dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
const int dx_8[]={1,1,0,-1,-1,-1,0,1}, dy_8[]={0,-1,-1,-1,0,1,1,1};
const long long MOD = 1e9+7;

// typedef long long ll;
#define int long long

template <typename T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <typename T> inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template <typename T> inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template <typename T> inline T nHr(T a,T b){return nCr(a+b-1,b);}

signed main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B; cin >> A >> B;
  char ans[100][100];
  REP(i, 50) REP(j, 100){
    ans[i][j] = '#'; ans[i+50][j] = '.';
  }
  int cnt = 0;
  for(int i = 0; i < 50; i+=2){
    for(int j = 0; j < 100; j+=2){
      if(cnt == A-1) continue;
      ans[i][j] = '.';
      cnt++;
    }
  }
  cnt = 0;
  for(int i = 99; i >= 50; i-=2){
    for(int j = 0; j < 100; j+=2){
      if(cnt == B-1) continue;
      ans[i][j] = '#';
      cnt++;
    }
  }
  cout << 100 << ' ' << 100 << endl;
  REP(i, 100){
    REP(j, 100) cout << ans[i][j];
    cout << endl;
  }
}