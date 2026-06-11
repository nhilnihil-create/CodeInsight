#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int N,A,B,C;
vl l(8);

int dfs(int k,int a,int b,int c){
  if(k == N){
    if(a*b*c == 0) return 1e8;
    else return abs(A-a)+abs(B-b)+abs(C-c) - 30;
  }
  int r0 = dfs(k+1,a,b,c);
  int r1 = dfs(k+1,a+l[k],b,c) + 10;
  int r2 = dfs(k+1,a,b+l[k],c) + 10;
  int r3 = dfs(k+1,a,b,c+l[k]) + 10;
  return min(min(r0,r1),min(r2,r3));
}

int main(){
  cin >> N >> A >> B >> C;
  rep(i,N) cin >> l.at(i);
  cout << dfs(0,0,0,0) << endl;
}