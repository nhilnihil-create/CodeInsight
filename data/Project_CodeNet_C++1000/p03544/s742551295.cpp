#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  long long a[86];
  a[0] = 2;
  a[1] = 1;
  scanf("%d",&n);
  
  
  for(int i = 2; i <= n; i++)a[i] = a[i-1] + a[i-2];
    printf("%lld",a[n]);
}