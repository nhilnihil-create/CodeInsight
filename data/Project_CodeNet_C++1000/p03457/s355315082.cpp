#include<bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  for (int i=0, dt=0, dx=0, dy=0; i<N; i++){
    int t, x, y; cin >> t >> x >> y;
    int st=abs(t-dt), di=abs(x-dx)+abs(y-dy);
    if(di>st||(di+st)&1){
      cout << "No\n";
      return 0;
    }
    dt = t, dx = x, dy = y;
  }
  cout << "Yes";
}