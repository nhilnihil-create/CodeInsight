#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vvi vector< vector<int> >
#define vi vector<int>
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define shosu(X) fixed << setprecision(X)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}



int main(){
  int a, b;
  cin >> a >> b;
  bool res[100][100];
  REP(i, 50) REP(j, 100) res[i][j] = false;
  FOR(i, 50, 100) REP(j, 100) res[i][j] = true;
  int cnt = 0;
  cout << 100 << " " << 100 << endl;
  REP(i, 25){
    REP(j, 50){
      if(cnt++ >= (b -1)) break;
      res[i*2+1][j*2+1] = true;
    }
  }
  cnt = 0;
  FOR(i, 25, 50){
    REP(j, 50){
      if(cnt++ >= (a - 1)) break;
      res[i*2 + 1][j*2+1] = false;
    }
  }
  REP(i, 100){
    REP(j, 100){
      if(!res[i][j]) cout << '.';
      else cout << '#';
    }
    cout << endl;
  }
} 	
