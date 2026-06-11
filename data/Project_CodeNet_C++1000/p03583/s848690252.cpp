#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin>>N;
  ll h,n,w;
  for(ll i=1;i<=3500;i++){
    for(ll j=1;j<=3500;j++){
      if(4*i*j-N*i-N*j>0&&(N*i*j)%(4*i*j-N*i-N*j)==0){
        h=i;
        n=j;
        w=N*h*n/(4*h*n-N*n-N*h);
        break;
      }
    }
  }
  cout<<h<<" "<<n<<" "<<w<<endl;
}
