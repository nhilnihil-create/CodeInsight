#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,m,n) for(int i=(m);i<(n);i++)
#define fore(i,a) for(auto &i:a)
#define debug(a,b) cout << "debug : " << a << " , "<< b << endl
using ll=long long;
const ll INF=1LL<<60;
const ll mod=1E9+7;

int sub(int a,int b){return (a^b)-a-b;}

int main(){
  int n;
  cin >> n;
  vector<int>a(n),sum(n+1,0);
  rep(i,n)cin >> a[i];
  int r=0,l=0;
  ll cnt=0,S=0;
  for(;l<n;l++){
    while(r<n&&sub(S,a[r])==0){
      S+=a[r];
      r++;
    }
    if(r<n&&r-l==0)r++;
    cnt+=r-l;
    S-=a[l];
  }
  cout << cnt << endl;
}

