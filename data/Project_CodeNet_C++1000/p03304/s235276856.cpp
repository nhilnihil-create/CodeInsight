#include<bits/stdc++.h>
using namespace std;
int main(){
  long double n,m,d;scanf("%Lf%Lf%Lf",&n,&m,&d);
  long double ans = (n-d)*(1+(d!=0))*(m-1)/n/n;
  printf("%.8Lf\n",ans);
}