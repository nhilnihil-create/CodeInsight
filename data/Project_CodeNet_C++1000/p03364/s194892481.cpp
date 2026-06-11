#include<iostream>
#include<string>
using namespace std;
int N_MAX = 300;
int main()
{
  int n,i,j,b,ii,jj,res=0;
  bool f;
  string s[N_MAX];
  cin >> n;
  for(i=0;i<n;i++)
    cin >> s[i];
  for(b=0;b<n;b++){
    f=false;
    for(i=0;i<n;i++){
      ii=i-b;
      if(ii<0) ii+=n;
      for(j=0;j<n;j++){
        jj=j+b;
        if(jj>=n) jj-=n;
        if(jj<=i) continue;
        if(s[i][j]!=s[jj][ii]){
          f=true;
          break;
        }
      }
      if(f) break;
    }
    if(!f) res++;
  }
  res*=n;
  cout << res << endl;
  return 0;
}
