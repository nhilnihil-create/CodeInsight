#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int main(){
  int a,b;
  cin >> a >> b;
  a--;b--;
  vector<vector<char>> data1(50,vector<char>(100,'.'));
  vector<vector<char>> data2(50,vector<char>(100,'#'));
  rep(i,(a/50)+1){
    long tmp;
    if(i == a/50) tmp = a%50;
    else tmp = 50;
    rep(j,tmp){
      data2[i*2][j*2] = '.';
    }
  }
  rep(i,(b/50)+1){
    long tmp;
    if(i == b/50) tmp = b%50;
    else tmp = 50;
    rep(j,tmp){
      data1[i*2][j*2] = '#';
    }
  }
  cout << 100 << " " << 100 << endl;
  rep(i,50){
    rep(j,100) cout << data1[i][j];
    cout << endl;
  }
  rep(i,100) cout << "#";
  cout << endl;
  rep(i,49){
    rep(j,100) cout << data2[i][j];
    cout << endl;
  }
}
