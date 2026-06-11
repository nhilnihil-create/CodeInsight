#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,M;
  string S,T;
  cin>>N>>M>>S>>T;
  int K=__gcd(N,M);
  for(int i=0;i<K;i++)
    if(S[N/K*i]!=T[M/K*i]){
      puts("-1");
      return 0;
    }
  cout<<N/K*M<<endl;
}
