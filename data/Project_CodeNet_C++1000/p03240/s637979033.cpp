#include <iostream>
using namespace std; using P=pair<int,int>; using ll=long long;

int main() {
  int n; cin>>n;
  ll x[n],y[n],h[n];
  for(int i=0;i<n;i++) cin>>x[i]>>y[i]>>h[i];
  for(ll cx=0;cx<=100;cx++) {
    for(ll cy=0;cy<=100;cy++) {
      ll he;
      // h[i]==0のとき、値が一意に求まらない
      for(int i=0;i<n;i++) if (h[i]!=0) {he=h[i]+abs(x[i]-cx)+abs(y[i]-cy); break;}
      if (he<=0) continue; // これはありえない
      bool ok=true;
      //cout<<cx<<" "<<cy<<" "<<he<<endl;
      for(int i=0;i<n;i++) {
        if (max(he-abs(x[i]-cx)-abs(y[i]-cy),0LL) != h[i]) {ok=false; break;}
      }
      if (ok) {
        cout<<cx<<" "<<cy<<" "<<he<<endl;
        return 0;
      }
    }
  }
  //cerr<<"OMG"<<endl;
}