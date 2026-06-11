#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
  char S[100001];
  scanf("%s",S);
  int len=strlen(S),cnta=0,cntb=0,cntc=0;
  for(int i=0;i<len;i++){
    if(S[i]=='a') cnta++;
    else if(S[i]=='b') cntb++;
    else if(S[i]=='c') cntc++;
  }
  int MIN=min(cnta,min(cntb,cntc));
  cnta-=MIN;cntb-=MIN;cntc-=MIN;
  if(cnta==0&&cntb==0&&cntc==0){
    printf("YES\n");return 0;
  }else if(cnta==0&&cntb==0){
    if(cntc==1){
      printf("YES\n");return 0;
    }else{
      printf("NO\n");return 0;
    }
  }else if(cntb==0&&cntc==0){
    if(cnta==1){
      printf("YES\n");return 0;
    }else{
      printf("NO\n");return 0;
    }
  }else if(cntc==0&&cnta==0){
    if(cntb==1){
      printf("YES\n");return 0;
    }else{
      printf("NO\n");return 0;
    }
  }else if(cnta==0){
    if(cntb==1&&cntc==1){
      printf("YES\n");return 0;
    }else{
      printf("NO\n");return 0;
    }
  }else if(cntb==0){
    if(cntc==1&&cnta==1){
      printf("YES\n");return 0;
    }else{
      printf("NO\n");return 0;
    }
  }else if(cntc==0){
    if(cnta==1&&cntb==1){
      printf("YES\n");return 0;
    }else{
      printf("NO\n");return 0;
    }
  }else{
    printf("NO\n");return 0;
  }
}
