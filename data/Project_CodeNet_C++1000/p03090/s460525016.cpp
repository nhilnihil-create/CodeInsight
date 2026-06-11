#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  if(n%2==0){
    cout<<(n-2)*n/2<<endl;
    rep(i,n){
      for(int j=i+1;j<n;j++){
        if(j+i!=n-1) cout<<i+1<<" "<<j+1<<endl;
      }
    }
  }else{
    cout<<(n-1)*(n-1)/2<<endl;
    rep(i,n-1){
      for(int j=i+1;j<n-1;j++){
        if(j+i!=n-2) cout<<i+1<<" "<<j+1<<endl;
      }
      cout<<i+1<<" "<<n<<endl;
    }
  }
}