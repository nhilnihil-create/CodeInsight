#include<bits/stdc++.h>
using namespace std;
 
int main(){
  long long n, a, b, mn = 1e15, sm = 0;
  scanf("%lld", &n);
  for(int i = 0; i < n; i++){
    scanf("%lld%lld", &a, &b);
    sm += a;
    if(a > b) mn = min(mn, b);
  }
  printf("%lld\n", (mn != 1e15 ? sm-mn : 0));
}
