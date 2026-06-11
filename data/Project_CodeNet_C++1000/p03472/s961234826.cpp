#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  int N,H,i,a,b,c;scanf("%d%d",&N,&H);
  pair<int,bool> K[N<<1];
  for(i=0;i<N;i++){
    scanf("%d%d",&a,&b);
    K[i] = make_pair(b,1);
    K[N+i] = make_pair(a,0); 
  }
  sort(K,K+(N<<1),greater<pair<int,bool>>());
  c = 0;
  for(i=0;i<(N<<1);i++){
    if(K[i].second == 1){
      H -= K[i].first;
      c++;
      if(H <= 0) break;
    }
    else{
      c += (H-1)/K[i].first+1;
      break;
    }
  }
  printf("%d\n",c);
}