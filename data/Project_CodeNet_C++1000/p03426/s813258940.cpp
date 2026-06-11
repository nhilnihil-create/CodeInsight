#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int N_MAX=90001;
int main()
{
  int h,w,d,q,l,r,t,i,j;
  int a[N_MAX],b[N_MAX],c[N_MAX];
  cin >> h >> w >> d;
  for(i=0;i<h;i++)
    for(j=0;j<w;j++){
      cin >> t;
      a[t]=i;
      b[t]=j;
    }
  fill(c,c+d+1,0);
  for(i=d+1;i<=h*w;i++)
    c[i]=c[i-d]+abs(a[i]-a[i-d])+abs(b[i]-b[i-d]);
  cin >> q;
  for(i=0;i<q;i++){
    cin >> l >> r;
    cout << c[r]-c[l] << endl;
  }
  return 0;
}
