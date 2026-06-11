#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

int main() {
  bool ifprime[55556];
  rep(i,55556) ifprime[i]=true;
  ifprime[0]=false;
  ifprime[1]=false;
  vector<int> primes;
  rep(i,55556) if(ifprime[i]){
    primes.push_back(i);
    int k=2*i;
    while(k<=55555){
      ifprime[k]=false;
      k+=i;
    }
  }
  
  int n;
  cin>>n;
  vector<int> ans;
  for(int num:primes){
    if(num%5==2) ans.push_back(num);
    if(ans.size()==n) break;
  }
  for(auto num:ans) cout<<num<<" ";
  cout<<endl;
  return 0;
}