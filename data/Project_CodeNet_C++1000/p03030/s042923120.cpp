#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  pair<string,int> op[N],np[N];
  for(int P,i=0;i<N;i++)
  {
    string S;cin>>S>>P;
    op[i].first=S,op[i].second=100-P;
    np[i].first=S,np[i].second=100-P;
  }
  sort(np,np+N);
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      if(op[j].first==np[i].first&&op[j].second==np[i].second)printf("%d\n",j+1);
    }
  }
}
