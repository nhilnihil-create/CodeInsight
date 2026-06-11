#include<iostream>
#include<algorithm>
int N_MAX=500;
using namespace std;
int main()
{
  int n,m,q,l,r,i,j,k;
  int a[N_MAX][N_MAX];
  cin >> n >> m >> q;
  for(i=0;i<n;i++)
    fill(a[i],a[i]+n,0);
  for(k=0;k<m;k++){
    cin >> l >> r;
    a[l-1][r-1]++;
  }
  for(k=1;k<n;k++)
    for(i=0;i<n-k;i++){
      j=i+k;
      a[i][j]+=a[i][j-1]+a[i+1][j]-a[i+1][j-1];
    }
  for(k=0;k<q;k++){
    cin >> l >> r;
    cout << a[l-1][r-1] << endl;
  }
  return 0;
}