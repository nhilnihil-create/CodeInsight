#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  char b;
  cin>>b;
  char ans;
    if(b=='A') ans='T';
    else if(b=='T') ans='A';
    else if(b=='G') ans='C';
    else ans='G';
  
  cout <<ans <<endl;
  return 0;
}