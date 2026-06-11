#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
int x[100010],y[100010],t[100010];
  
int main(){
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>t[i]>>x[i]>>y[i];
  for(int i=1;i<=n;i++){
    int T=t[i]-t[i-1];
    int X=x[i]-x[i-1];
    int Y=y[i]-y[i-1];
    //cout<<T<<X<<Y<<endl;
    int po=abs(X)+abs(Y);
    if(T<po || (T-po)%2!=0){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}