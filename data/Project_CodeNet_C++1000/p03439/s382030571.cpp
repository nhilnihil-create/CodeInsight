#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  string s;
  cout<<0<<endl;
  cout<<flush;
  cin>>s;
  int a;
  if(s=="Male")a=1;
  else if(s=="Female")a=0;
  else return 0;
  int l=0,r=N,m;
  for(int i=0;i<19;i++){
    m=(l+r)/2;
    cout<<m<<endl;
    cout<<flush;
    string S;
    cin>>S;
    int c;
    if(S=="Male")c=1;
    else if(S=="Female")c=0;
    else return 0;
    if(m%2){
      if(c==a)r=m;
      else l=m;
    }
    else{
      if(c==a)l=m;
      else r=m;
    }
  }
  return 0;
}
