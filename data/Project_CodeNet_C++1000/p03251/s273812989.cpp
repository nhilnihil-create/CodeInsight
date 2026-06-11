#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using vi  = vector<int>;
int main(){
    int n,m,x,y;
    cin >>n>>m>>x>>y;
    int xmax=-200, ymin=200;
    rep(i,n){
      int a;
      cin>>a;
      xmax = max(xmax, a);
    }
    rep(i,m){
      int a;
      cin>>a;
      ymin = min(ymin, a);
    }
    int z = min(ymin, y);
    if(x<z && xmax<z)
        cout << "No War" << endl;
    else
        cout << "War" << endl;
    return 0;
}