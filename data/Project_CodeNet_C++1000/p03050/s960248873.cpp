#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
signed main(){
  int n;cin>>n;
  int res=0;
  for(int i=1;i<=1000050;i++){
    if(i>=n)break;
    int buf=n;
    buf-=i;
    if(buf%i==0&&buf!=0){
      int hoge=buf/i;
      if(n%hoge==0)continue;
      if(i>=hoge)continue;
      res+=buf/i;
      //printf("i=%lld buf/i=%lld\n",i,buf/i);
      //cout<<"res="<<res<<endl;
    }
  }
  cout<<res<<endl;
  return 0;
}