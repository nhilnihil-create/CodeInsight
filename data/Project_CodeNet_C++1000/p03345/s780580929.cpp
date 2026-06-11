#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  ll A,B,C,K;
  cin>>A>>B>>C>>K;
  if(K%2==0){
    cout<<A-B<<endl;
  }else{
    ll x=B+C;
    ll y=C+A;
    cout<<x-y<<endl;
  }
}
