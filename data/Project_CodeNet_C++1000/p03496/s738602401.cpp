#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n, a[55], mxa = 0, mna = 0, i, k;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
    if(a[mxa] < a[i]) mxa = i;
    if(a[mna] > a[i]) mna = i;
  }
  k = a[mxa] + a[mna] > 0 ? mxa : mna;
  
  if(a[mxa] > 0 && a[mna] < 0){
    printf("%d\n", 2*(n-1));
    for(i = 0; i < n; i++){
      if(i == k) continue;
      printf("%d %d\n", k+1, i+1);
    }
  }else printf("%d\n", n-1);
  
  if(a[k] > 0) for(i = 1; i < n; i++) printf("%d %d\n", i, i+1);
  else for(i = n-1; i > 0; i--) printf("%d %d\n", i+1, i);
}