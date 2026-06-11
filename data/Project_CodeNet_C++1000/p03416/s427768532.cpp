#include<bits/stdc++.h>
using namespace std;

int main()
{
  int A,B,ans=0;scanf("%d %d",&A,&B);
  for(int ioooi=1;ioooi<10;ioooi++)for(int oioio=0;oioio<10;oioio++)for(int i=0;i<10;i++)if(ioooi*10001+oioio*1010+i*100>=A&&ioooi*10001+oioio*1010+i*100<=B)ans++;
  printf("%d\n",ans);
}