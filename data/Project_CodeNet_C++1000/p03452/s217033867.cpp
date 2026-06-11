#include<cstdio>
#include<algorithm>
#define MAX 200005
using namespace std;

struct A{ int par; int dis; }; 
A a[MAX];

void getp(int x){
  if(a[x].par != x){
    getp(a[x].par);
    a[x].dis += a[a[x].par].dis;
    a[x].par = a[a[x].par].par;
  }
}

int main(){
  int n, m, l, r, d, i;
  bool flag = true;
  scanf("%d%d", &n, &m);
  for(i = 1; i <= n; i++){
    a[i].par = i;
    a[i].dis = 0;
  }
  for(i = 0; i < m; i++){
    scanf("%d%d%d", &l, &r, &d);
    getp(l);
    getp(r);
    if(a[l].par == a[r].par){
      if(a[r].dis - a[l].dis != d) flag = false;
    }else{
      a[a[r].par].dis = -a[r].dis + d + a[l].dis;
      a[a[r].par].par = a[l].par;
    }
  }
  if(flag) printf("Yes\n");
  else printf("No\n");
}