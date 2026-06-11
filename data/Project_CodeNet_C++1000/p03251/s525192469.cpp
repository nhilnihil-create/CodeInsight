#include<bits/stdc++.h>
using namespace std;


int main(){
  int n,m,X,Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n),y(m);
  for(int i=0;i<n;++i) cin >> x[i];
  for(int i=0;i<m;++i) cin >> y[i];

  bool ok=true;
  if(Y-X<1) ok=false;
  if(!ok){
    cout << "War" << endl;
    return 0;
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  ok=false;
  for(int z=Y;z>X;--z){
    if(x[n-1]<z && y[0]>=z){
      ok=true;
      break;
    }
  }
  if(ok) cout << "No War" << endl;
  else cout << "War" << endl;
  return 0;
}
