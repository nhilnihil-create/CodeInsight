#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

int main(){
  int n,m;
  cin>>n>>m;
  int x=m/n;//最も効率が良い＝すべて等しいときを超える答えはない
  while(true){
    int temp=m-x*n;//これでnこの数がtemp+x,x,x,x,,,となる
    //cout<<x<<" "<<temp<<endl;
    if(temp%x==0) break;
    x--;
    if(x==1)  break;
  }
  cout<<x<<endl;
  return 0;
}