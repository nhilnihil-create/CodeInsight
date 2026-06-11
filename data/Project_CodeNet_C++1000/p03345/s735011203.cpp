#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c,k;scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
  printf("%lld\n",((k%2) ? b-a:a-b));
}