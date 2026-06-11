#include<bits/stdc++.h>
using namespace std;
const int N=110000;
char a[N];
int but[N];
int n;
void outa()
{
  int pos=-1;
  for(int i=25;i>=0;i--) if(!but[i]) pos=i;
  printf("%s",a);
  printf("%c\n",(char)(pos+'a')); 
  return; 
}
void outb()
{
  int pos=-1;
  for(int i=1;i<n;i++) if(a[i-1]<a[i]) pos=i-1;
  for(int i=0;i<pos;i++) printf("%c",a[i]);
  for(int i=pos;i<n;i++) but[a[i]-'a']--;
  int las=-1;
  for(int i=25;i>=0;i--) if(!but[i]&&i>a[pos]-'a') las=i;
  printf("%c\n",(char)('a'+las));
  return;
}
int main()
{
  scanf("%s",a);
  n=strlen(a);
  for(int i=0;i<n;i++) but[a[i]-'a']++;
  int flag=0;
  for(int i=1;i<n;i++) if(a[i-1]-1!=a[i]) flag=1;
  if(!flag&&n==26) return printf("-1\n"),0;
  if(n==26) outb();
  else outa();
  return 0;
}