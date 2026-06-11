#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;i++)

const ll INF = 1001001001;

const double PI=3.141592653;

const ll sosu = 1000000007;//大きい素数

//提出のときに言語がc＋＋似合っていることを確認する

ll f(ll x){
  if(x==1) return 1;
  return 2*f(x/2)+1;
}
int main(){
  char x,y;
  cin>>x>>y;
  if(x>y) cout<<">"<<endl;
  else if(x==y) cout<<"="<<endl;
  else cout<<"<"<<endl;
  return 0;
}
