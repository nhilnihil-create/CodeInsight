#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  int N;
  string S;
  cin>>N>>S;
  vector<ll> counter(26,0);
  for(int i=0;i<N;i++){
    int x=S.at(i)-'a';
    counter.at(x)++;
  }

  ll ans=1;
  for(int i=0;i<26;i++){
    ans*=counter.at(i)+1;
    ans%=MOD;
  }
  ans--;
  cout<<ans<<endl;
}
