#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main(){
  ll A, B; cin >> A >> B;
  string s = ".#";
  //A>Bなら白黒の役割入れ替える
  if(A>B){
    swap(A,B);
    s = "#.";
  }
  //以下，A<=B
  //Aの方にs[0],Bの方にs[1]を割り当てる
  vector<string> grid(100);
  REP(i,100) REP(j,100) grid[i].push_back(s[0]);

  //左上(x,y)として黒の連結成分つくる
  auto create_black = [&](ll x, ll y){
    REP(i,3) REP(j,3) if(i!=1||j!=1){
      grid[x+i][y+j] = s[1];
    }
  };

  //黒の連結成分B個つくる
  ll yoko = B%25;
  ll tate = B/25+1;
  REP(i,tate){
    ll L = (i==tate-1) ? yoko : 25;
    REP(j,L){
      create_black(4*i,4*j);
    }
  }
  //このとき白の連結成分B+1個できている
  //A個に減らすため，B-A+1個塗りつぶす
  yoko = (B-A+1)%25;
  tate = (B-A+1)/25+1;
  REP(i,tate){
    ll  L = (i==tate-1) ? yoko : 25;
    REP(j,L){
      grid[1+4*i][1+4*j] = s[1];
    }
  }

  cout << 100 << " " << 100 << endl;
  REP(i,100) cout << grid[i] << endl;
}