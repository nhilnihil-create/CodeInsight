#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)
using namespace std;
using p=pair<int,int>;

int main() {
  int a,b,c,n;
  cin >>a>>b>>c>>n;
  int f=0;
  rep(i,a+1){
    rep(j,b+1){
      rep(k,c+1){
        int m =500*i + 100*j +50 *k;
        if(m==n){
          f++;
        }
      }
    }
  }
  cout << f << endl;


}
