#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
  int N;cin>>N;
  bool flag =false;
  rep(i,26){
    rep(j,15){
      if(N==(4*i)+(7*j)){
        flag=true;
        break;
      }
    }
  }
   if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}