#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 100001;
int main()
{
  int n,m,i,a,b,t,res=0;
  int c[N_MAX];
  cin >> n >> m;
  fill(c+1,c+n+1,n+1);
  for(i=0;i<m;i++){
    cin >> a >> b;
    c[a]=min(c[a],b);
  }
  t=n+1;
  for(i=1;i<n;i++){
    t=min(t,c[i]);
    if(t==i+1){
      res++;
      t=n+1;
    }
  }
  cout << res << endl;
  return 0;
}