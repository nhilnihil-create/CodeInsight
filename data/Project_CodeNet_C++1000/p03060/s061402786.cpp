#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define INT(str) stoi((str), 0)
#define INTB(str) stoi((str), 0, 2) // 2進数の文字列を int に
 
int main() {
  int N;
  cin >> N;
  
  vi V = vi(N);
  REP(i, N) cin >> V.at(i);
  
  vi C = vi(N);
  REP(i, N) cin >> C.at(i);
  
  int r = 0;
  REP(i, N) {
    if (C.at(i) < V.at(i))
      r += V.at(i) - C.at(i);
  }
  
  cout << r << endl;
}