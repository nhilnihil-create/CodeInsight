#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

int main(){
  long long a,b;
  cin>>a>>b;
  long long suma,sumb;//f(0,a-1),f(b)
  a--;
  if(a%4==0) suma=a;
  if(a%4==1) suma=1;
  if(a%4==2) suma=a+1;
  if(a%4==3) suma=0;
  
  if(b%4==0) sumb=b;
  if(b%4==1) sumb=1;
  if(b%4==2) sumb=b+1;
  if(b%4==3) sumb=0;
  
  cout<<(sumb^suma)<<endl;
  return 0;
}