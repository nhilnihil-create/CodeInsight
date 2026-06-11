#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
   map<int,int> m;
  m[1]=0;
  m[2]=0;
  m[3]=0;
  m[4]=0;
  int a,b;
  cin >> a >> b;
  m[a]++;
  m[b]++;
  int c,d;
  cin >> c >> d;
  m[c]++;
  m[d]++;
  int e,f;
  cin >> e >> f;
  m[e]++;
  m[f]++;
  if(m[1]==3 || m[2]==3 || m[3]==3 || m[4]==3)
  cout << "NO" << endl;
  else
  cout << "YES" << endl;
}

