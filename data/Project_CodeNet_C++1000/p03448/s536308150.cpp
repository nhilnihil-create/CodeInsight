#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a,b,c,x; ll ans=0;
  cin>>a>>b>>c>>x;
  for(int i=0; i*500<=x && i<=a; i++){
    for(int j=0; i*500+j*100<=x && j<=b; j++){
      if((x-i*500-j*100)/50<=c){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}