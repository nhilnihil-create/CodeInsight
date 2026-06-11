#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
bool prime[101];
void init(){
  int i,j;
  prime[0] = prime[1] = false;
  fill(prime+2,prime+101,1);
  for(i=2;i<=7;i++){
    if(!prime[i]) continue;
    for(j=i+i;j<=100;j+=i) prime[j] = false;
  }
}
int main(){
  init();
  int N,CN,c,i,j,k;scanf("%d",&N);
  vector<int> s;
  for(i=2;i<=100;i++){
    if(!prime[i]) continue;
    c = 0;CN = N;
    while(CN){
      CN /= i;c += CN;
    }
    s.emplace_back(c);
  }
  int ans = 0;
  for(i=0;i<s.size();i++) ans += s[i] >= 74;
  for(i=0;i<s.size();i++){
    for(j=0;j<s.size();j++){
      if(i==j) continue;
      ans += s[i] >= 2 && s[j] >= 24;
      ans += s[i] >= 4 && s[j] >= 14;
    }
  }
  for(i=0;i<s.size();i++){
    for(j=0;j<s.size()-1;j++){
      for(k=j+1;k<s.size();k++){
        if(i == j || i == k) continue;
        ans += s[i] >= 2 && s[j] >= 4 && s[k] >= 4;
      }
    }
  }
  printf("%d\n",ans);
}