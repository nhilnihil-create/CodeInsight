#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

#define _int64 long long

char s[210000];
short ma[1<<26];
int mi[1<<26];
int best[1<<26];

int main()
{
  int i,l,now,tmp,bma,btmp,ans,j,x,y;
  vector<int> q;
  scanf("%s",s);
  l=strlen(s);
  now=0;
  memset(best,-1,sizeof(best));
  best[0]=0;
  for (i=0;i<l;i++)
  {
    now^=(1<<(s[i]-'a'));
    tmp=2000000000;
    if (best[now]!=-1) tmp=best[now]+1;
    for (j=0;j<26;j++)
    {
      y=(now^(1<<j));
      if ((best[y]!=-1)&&(best[y]+1<tmp)) tmp=best[y]+1;
    }
    if ((best[now]==-1)||(tmp<best[now])) best[now]=tmp;
    ans=best[now];
  }
  if (ans==0) ans=1;
  printf("%d\n",ans);
  return 0;
}