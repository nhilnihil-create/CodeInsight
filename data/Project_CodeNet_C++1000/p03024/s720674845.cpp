#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=15;

char s[N+9];
int n;

void into(){
  scanf("%s",s+1);
  n=strlen(s+1);
}

int ans;

void Get_ans(){
  ans+=15-n;
  for (int i=1;i<=n;++i) ans+=s[i]=='o';
}

void work(){
  Get_ans();
}

void outo(){
  puts(ans>=8?"YES":"NO");
}

int main(){
  into();
  work();
  outo();
  return 0;
}