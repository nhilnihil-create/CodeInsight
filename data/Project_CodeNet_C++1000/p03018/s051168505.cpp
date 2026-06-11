#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int h[200005]={0};
int used[200005]={0};
int main(){
  string S;
  cin>>S;
  int n=S.size();
//  cout<<n<<endl;
  ll ans=0;
for(int j=1;j<=n;j++){
  if(S[j-1]=='A')h[j]=1;
  else if(S[j-1]=='B')h[j]=2;
  else h[j]=3;
}
  int i=1;
    ll a =0;
  while(i<=n){

    if(h[i]==2&&h[i+1]==3){
      ans+=a;
      i+=2;
    }
    else if(h[i]==1){
      a++;
      i++;
    }
    else{
      i++;
      a=0;
    }

  }
  cout<<ans<<endl;
}
