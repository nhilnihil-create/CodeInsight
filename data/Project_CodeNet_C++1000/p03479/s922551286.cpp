#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  ll X,Y;
  cin>>X>>Y;
  ll ans=1;
  while(true){
    if(X*2>Y){
      break;
    }
    X*=2;
    ans++;
  }
  cout<<ans<<endl;
}