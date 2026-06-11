#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  string s;
  cin>>N>>s;
  int r=0,b=0;
  for(int i=0;i<N;i++){
    if(s[i]=='R')r++;
    if(s[i]=='B')b++;
  }
  if(r>b)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
