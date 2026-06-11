#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(void){
  int h,w,d,a,i,j,x[90010],y[90010],t[90010]={},q,l,r,ans;
  cin >> h >> w >> d;
  for (i=0;i<h;i++) for (j=0;j<w;j++){
    cin >> a;
    x[a]=i;
    y[a]=j;
  }
  for (i=0;i+d<=h*w;i++){
    t[i+d]+=t[i]+abs(x[i]-x[i+d])+abs(y[i]-y[i+d]);
  }
  
  cin >> q;
  for (i=0;i<q;i++){
    cin >> l >> r;
    cout << t[r]-t[l] << endl;
  }
  return 0;
}