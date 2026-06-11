#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string C,CC;
  cin>>C>>CC;
  string ans="YES";
  if(C[0]!=CC[2]||C[1]!=CC[1]||C[2]!=CC[0])ans="NO";
  cout<<ans<<endl;
  return 0;
}