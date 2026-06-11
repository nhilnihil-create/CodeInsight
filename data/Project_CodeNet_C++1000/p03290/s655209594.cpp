#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n);++i)
const int INF =1001001001;

int a[10][2];
int main() {
  int D,G;
  cin>>D>>G;
  rep(i,D){
    cin>>a[i][0]>>a[i][1];
  }
  long long mins=INF;
  rep(bit,1<<D){
    long long mons=0;
    long long tens=0;
    rep(i,D){
      if(bit>>i&1){
        mons+=a[i][0];
        tens+=a[i][1]+100*(i+1)*a[i][0];
      }
    }
    if(tens>=G){
      mins=min(mins,mons);
    }
      rep(j,D){
        long long mons1=mons;
        long long tens1=tens;
        if(!(bit>>(D-j-1)&1)){
          rep(i,a[D-j-1][0]){
            if(tens1>=G){
              mins=min(mins,mons1);
              break;
            }
            mons1++;
            tens1+=100*(D-j);
          }
          break;
        }
      }
    }
  cout<<mins<<endl;
}