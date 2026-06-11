#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  ll A,B,C,K;
  cin>>A>>B>>C>>K;
  if(K%2==0){
    cout<<A-B<<endl;
  }
  if(K%2!=0){
    cout<<B-A<<endl;
  }
}   