#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 30000;
typedef long long ll;
int main()
{
  int n,i,j,k,cc,bb=0,res=0;
  int p[3]={3,5,7};
  ll m=10;
  ll c[4][N_MAX],b[4][N_MAX];
  bool f;
  cin >> n;
  if(n<357){
    cout << "0" << endl;
    return 0;
  }
  b[0][bb]=3; b[1][bb]=1; b[2][bb]=0; b[3][bb]=0; bb++;
  b[0][bb]=5; b[1][bb]=0; b[2][bb]=1; b[3][bb]=0; bb++;
  b[0][bb]=7; b[1][bb]=0; b[2][bb]=0; b[3][bb]=1; bb++;
  while(true){
    f=0;
    cc=0;
    for(j=0;j<3;j++){
      for(i=0;i<bb;i++){
        for(k=0;k<4;k++)
          c[k][cc]=b[k][i];
        c[0][cc]+=m*p[j];
        if(c[0][cc]>n){
          f=1;
          break;
        }
        c[j+1][cc]++;
        if(c[1][cc]>0&&c[2][cc]>0&&c[3][cc]>0)
          res++;
        cc++;
      }
      if(f==1)
        break;
    }
    if(f==1)
      break;
    for(k=0;k<4;k++)
      copy(c[k],c[k]+cc,b[k]);
    bb=cc;
    m*=10;
  }
  cout << res << endl;
  return 0;
}