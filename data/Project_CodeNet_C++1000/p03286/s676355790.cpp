#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


#define INF 1000000000000

int pow(int n,int k){
  int q=1;
  for(int i=0;i<k;i++){
    q*=n;
  }
  return q;
}

signed main()
 {
  int n;
  cin>>n;
  if(n==0){cout<<'0';exit(0);}
  vector<int>ans(0);
  for(int i=35; i>=0; i--){
    if(i%2==0){
      int k=i/2+1;
      if((pow(4,k-1)-1)/3<n&&n<=(pow(4,k)-1)/3){
        ans.push_back(1);
        n-=pow(4,k-1);
      }
      else{
        ans.push_back(0);
      }
    }
    if(i%2==1){
      int k=(i+1)/2;
      if((1-pow(4,k))*2/3<=n&&n<(1-pow(4,k))*2/3+2*pow(4,k-1)){
        ans.push_back(1);
        n-=pow(4,k-1)*2*(-1);
      }
      else{
        ans.push_back(0);
      }
    }
  }
  int l=0;
  rep(i,40){
    if(ans[i]==0&&ans[i+1]!=0){l=i+1;break;}
  }
  for(int i=l;i<ans.size();i++){
    cout<<ans[i];
  }
 }
