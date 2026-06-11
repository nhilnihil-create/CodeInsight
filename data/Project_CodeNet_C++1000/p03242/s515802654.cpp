#include<bits/stdc++.h>
using namespace std;
int main(){
    char s[5];scanf("%s",s);
    for(int i=0;i<3;i++){
          if(s[i]=='1') s[i]='9';
          else if(s[i]=='9') s[i]='1';
    } 
    printf("%s\n",s);
}