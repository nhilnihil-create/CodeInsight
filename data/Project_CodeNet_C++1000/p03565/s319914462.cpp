#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
 char s[50],t[50];
 vector<int>ques(50);
 scanf("%s",s);
 scanf(" %s",t);
 int slen,tlen;
 slen=strlen(s);
 tlen=strlen(t);
 int i,j;
 for(i=0;i<slen;i++){
  ques[i]=0;
  //printf("%d %c\n",i,s[i]);
 }
 for(i=slen;i>=0;i--){
  if(s[i]=='?'){
   if(i==49)ques[i]=1;
   else ques[i]+=1+ques[i+1];
   //printf("%d %c %d\n",i,s[i],ques[i]);
  }
 }
 int k=0;
 
 //何文字かが一致しているパターン
 bool flag2=0,flag3=0;k=0;
 int start=0;
 for(i=slen-1;i>=0;i--){
  flag2=0;
  if(s[i]=='?'||s[i]==t[0]){
   k=0;
   for(j=i;j<tlen+i;j++){
     //printf("i ga %d %c\n",i,s[j]);
    if(j>=slen||(s[j]!='?'&&s[j]!=t[k])){
     flag2=1;
    }
    k++;
    if(flag2){
     //puts("flag2 break");
     break;
    }
    if(j==tlen+i-1){
     //puts("ok flag3=1");
     start=i;flag3=1;
    }
   // printf("flag2 %d flag3 %d\n",flag2,flag3);
   if(flag3)break;
  }
  k=0;
  if(flag3){
   for(j=start;j<tlen+start;j++){
    s[j]=t[k];k++;
   // printf("j %d %c\n",j,s[j]);
    }
   }
  }
 if(flag3)break;
 }
 if(flag3){
  // puts("flag3");
  for(i=0;i<slen;i++){
   if(s[i]=='?')s[i]='a';
   printf("%c",s[i]);
   if(i==slen-1)return 0;
  }
 }
 puts("UNRESTORABLE");
return 0;}