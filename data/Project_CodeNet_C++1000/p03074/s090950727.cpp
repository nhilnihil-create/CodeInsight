#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int main(){
  int N,K,i;char c;scanf("%d %d\n",&N,&K);
  vector<int> v;v.emplace_back(0);
  bool p = 1;
  for(i=0;i<N;i++){
    scanf("%c",&c);
    if((c == '1') == p) v.back()++;
    else{
      v.emplace_back(1);
      p ^= 1;
    }
  }
  if(v.size() <= K*2+1){
    printf("%d\n",N);return 0;
  }
  int now = accumulate(v.begin(),v.begin()+K*2+1,0),ans = now;
  if(v.size()%2 == 0) v.emplace_back(0);
  for(i=K*2+1;i<v.size()-1;i+=2){
    now -= v[i-K*2-1]+v[i-K*2];
    now += v[i]+v[i+1];
    ans = max(ans,now);
  }
  printf("%d\n",ans);
}