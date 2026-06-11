#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
  int n,k,i,i1,i2,i3,i4,l,x[55],y[55],p;
  long s,ans=5e18;
  vector<int> xl,yl;
  cin >> n >> k;
  for (i=0;i<n;i++){
    cin >> x[i] >> y[i];
    xl.push_back(x[i]);
    yl.push_back(y[i]);
  }
  sort(xl.begin(),xl.end());
  sort(yl.begin(),yl.end());
  for (i1=0;i1<n-1;i1++) for (i2=i1+1;i2<n;i2++) for (i3=0;i3<n-1;i3++) for (i4=i3+1;i4<n;i4++){
    p=0;
    for (l=0;l<n;l++) if (x[l]>=xl[i1] && x[l]<=xl[i2] && y[l]>=yl[i3] && y[l]<=yl[i4])
      p++;
    s=(long)(xl[i2]-xl[i1])*(yl[i4]-yl[i3]);
    if (p>=k && ans>s) ans=s;
  }
  cout << ans << endl;
  return 0;
}