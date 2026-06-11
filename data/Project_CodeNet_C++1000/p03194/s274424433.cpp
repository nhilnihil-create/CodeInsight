#include "iostream"
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <cctype>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
using namespace std;
using ll=long long;
#define MOD  1000000007
ll n,p,ans=0;
ll flag[1000010];

int main(int argc, char const *argv[]) {

  memset(flag,0,sizeof(flag));
  std::cin >> n >> p;
  flag[1]=1;

if(p==1){
  std::cout << "1" << '\n';
  return 0;
}
if(n==1){
  std::cout << p << '\n';
  return 0;
}
for(int i=2; i<=sqrt(p); i++){
  ll m=p,cnt=0;
  while(m>0){
    if(m%i==0){
       m/=i;
       cnt++;
     }
     else break;
  if(n<=cnt) flag[i]++;
 }
}

for(int i=0; i<=sqrt(p); i++){
  if(flag[i]!=0) ans=i;
}
std::cout << ans << '\n';

  return 0;
}
