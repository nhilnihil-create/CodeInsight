#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main(){
  int N; cin >> N;
  long int h,w; cin >> h >> w;
  long int a,b;
  int r = 0;
  REP(i,N){
    cin >> a >> b;
    if(a>=h){
      if(b>=w){
        r++;
      }
    }
  }
  cout << r << "\n";
}