#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 51;
typedef pair<int,int> P;
int main()
{
  int n,m,i,j,res=0;
  cin >> n >> m;
  P b[N_MAX]; // 枝データ
  int c[N_MAX]; // 頂点iの属する集合番号
  int nc[N_MAX]; // 集合jの要素数
  int pc[N_MAX]; // 集合jの先頭の要素番号
  int pi[N_MAX]; // 頂点iと同じ集合の要素へのポインタ
  int i1,i2,s1,s2,p,pt;
  int c1,c2;
  for(i=0;i<m;i++)
    cin >> b[i].first >> b[i].second;
  for(j=0;j<m;j++){
  for(i=1;i<=n;i++){
    c[i]=i;
    nc[i]=1;
    pc[i]=i;
    pi[i]=0;
  }
  for(i=0;i<m;i++){
    if(i==j)
      continue;
    i1=b[i].first;
    i2=b[i].second;
    if(c[i1]!=c[i2]){
// 集合のマージここから
      s1=c[i1]; s2=c[i2];
      if(nc[s1]<nc[s2]){// 小さい方を潰す【重要】
        s1=c[i2]; s2=c[i1];
      }
      pt=pc[s1];
      p=pc[s2];
      pc[s1]=p;
      nc[s1]+=nc[s2];
      pc[s2]=0;
      nc[s2]=0;
      while(true){
        c[p]=s1;
        if(pi[p]==0) break;
        p=pi[p];
      }
      pi[p]=pt;
// 集合のマージここまで
    }
  }
  if(nc[c[1]]<n)
    res++;
  }
  cout << res << endl;
  return 0;
}