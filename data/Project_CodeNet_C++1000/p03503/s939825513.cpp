#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

int main(void) {
  int n;cin>>n;
  vector<int> f(n, 0);
  fr(i,n) {
    int a = 1;
    fr(j, 10){
      int x;cin>>x;
      f[i] += a*x;
      a *= 2;
    }
  }
  vector<vector<int>> p(n, vector<int>(11));
  fr(i, n) fr(j, 11) cin>>p[i][j];
  int v = -1000000000;
  Fr(i, 1023){
    int v_temp = 0;
    fr(j, n) {
      int t = 0;
      int a = i&f[j];
      while(a) {
        if(a%2) t++;
        a /= 2;
      }
      v_temp +=p[j][t];
    }
  v = max(v, v_temp);
  }
  cout << v << endl;
  return 0;
}