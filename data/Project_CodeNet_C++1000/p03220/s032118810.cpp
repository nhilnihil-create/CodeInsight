#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t,a;
  int cc=1<<30;
  int res;
  cin >> n >> t >> a;
  vector<int> h(n);
  for(int i=0;i<n;i++){
    cin >> h[i];
    int d=(t*1000-6*h[i])-a*1000;
    if(d<0)d=-d;
    if(cc>d)cc=d,res=i;
  }
  cout << res+1 << endl;
}
