#include<bits/stdc++.h>
using namespace std;

int main()
{
int N,Y;scanf("%d %d",&N,&Y);
for(int man=0;man<(Y/10000)+1;man++)for(int fsen=0;fsen<((Y-man*10000)/5000)+1;fsen++)
{
  int sen=(Y-man*10000-fsen*5000)/1000;
  if(man+fsen+sen==N&&man*10000+fsen*5000+sen*1000==Y){printf("%d %d %d\n",man,fsen,sen);return 0;}
}
printf("-1 -1 -1\n");
}