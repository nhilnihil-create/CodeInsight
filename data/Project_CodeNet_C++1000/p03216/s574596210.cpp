#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=1e9;
const long long LINF=1e18;
#define int long long
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
/*
*/
//main
signed main(){
  int N,Q;string s;cin>>N>>s>>Q;
  std::vector<int> v(Q);
  for(int i=0;i<Q;i++)cin>>v[i];
  int M;//待機してるMの数
  int nexD;//次のMに対してかかるDの数
  int pDM;//待機してるDMのペアの数
  int ans;
  for(int i=0;i<Q;i++){
    ans=M=nexD=pDM=0;
    for(int j=0;j<N;j++){
      if(s[j]=='D')nexD++;
      if(s[j]=='M'){
        M++;
        pDM+=nexD;
      }
      if(s[j]=='C')ans+=pDM;
      int A=j-v[i]+1;
      if(A<0)continue;
      if(s[A]=='D'){
        nexD--;
        pDM-=M;
      }
      if(s[A]=='M')M--;
    }
    cout<<ans<<endl;
  }
}
