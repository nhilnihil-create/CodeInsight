#include<cstdio>
using namespace std;

int main(){
  int a,b,flag;
  char s[101][101];
  scanf("%d %d",&a,&b);
  for(int i=0;i<100;i++)
    for(int j=0;j<=100;j++){
      if(j==100)
        s[i][j]='\0';
      else if(i<50)
        s[i][j]='#';
      else
        s[i][j]='.';
    }
  a--;
  b--;
  for(int i=1;i<49;i++)
    for(int j=1;j<99;j++){
      if(a>0){
        flag=1;
        for(int di=-1;di<=1;di++)
          for(int dj=-1;dj<=1;dj++)
            if(s[i+di][j+dj]=='.')
              flag=0;
        if(flag){
          s[i][j]='.';
          a--;
        }
      }
    }
  for(int i=51;i<99;i++)
    for(int j=1;j<99;j++){
      if(b>0){
        flag=1;
        for(int di=-1;di<=1;di++)
          for(int dj=-1;dj<=1;dj++)
            if(s[i+di][j+dj]=='#')
              flag=0;
        if(flag){
          s[i][j]='#';
          b--;
        }
      }
    }
  printf("100 100\n");
  for(int i=0;i<100;i++)
    printf("%s\n",s[i]);
}