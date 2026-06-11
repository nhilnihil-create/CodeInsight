#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb(x) push_back(x)
#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e3 + 5;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char smjer[4] = {'R', 'U', 'L', 'D'};

int n;
ll X[MAXN], Y[MAXN], pot[MAXN];

void done(){
  cout << -1;
  exit(0);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  pot[0] = 1;
  FOR(i, 1, 35)
    pot[i] = pot[i - 1] * 2;

  cin >> n;
  REP(i, n)
    cin >> X[i] >> Y[i];

  int par = (abs(X[0]) + abs(Y[0])) % 2;
  FOR(i, 1, n){
    if( (abs(X[i]) + abs(Y[i])) % 2 != par )
      done();
  }

  if(par == 0){
    REP(i, n)
      X[i] ++;
  }
  par = !par;

  cout << 31 + par << "\n";
  for(int i = 30; i >= 0; --i)
    cout << pot[i] << " ";
  if(par)
    cout << 1;
  cout << "\n";

  REP(i, n){
    int x = 0, y = 0;
    for(int j = 30; j >= 0; --j){
      REP(k, 4){
        ll nx = x + dx[k] * pot[j];
        ll ny = y + dy[k] * pot[j];
        //TRACE(nx); TRACE(ny);
        //TRACE( abs(nx - X[i]) + abs(ny - Y[i]) ); TRACE(pot[j]);
        if( abs(nx - X[i]) + abs(ny - Y[i]) < pot[j] ){
          x = nx;
          y = ny;
          cout << smjer[k];
          break;
        }
      }
    }

    if(par) cout << 'L';
    cout << "\n";
  }
}
