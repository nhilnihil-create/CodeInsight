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


int N, A, B, C;
int l[10];
int dfs(int n, int a, int b, int c){
  if (n==N){
    if (min({a,b,c})>0) return abs(a-A) + abs(b-B) + abs(c-C) - 30;
    else return 1000000000;
  }

  int ret0 = dfs(n+1, a, b, c); // 選ばない
  int ret1 = dfs(n+1, a+l[n], b, c) + 10;
  int ret2 = dfs(n+1, a, b+l[n], c) + 10;
  int ret3 = dfs(n+1, a, b, c+l[n]) + 10;
  return min({ret0, ret1, ret2, ret3});

}

int main(){
  cin >> N >> A >> B >> C;
  rep(i,N) cin >> l[i];

  cout << dfs(0,0,0,0) << endl;




  // cout << fixed << setprecision(10);
  
  return 0;
}