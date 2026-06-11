#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){
  ll n,a,b,c,d,e;
  cin >> n >> a >> b >> c >> d >> e;

  ll mini,time,movetime;

  mini=min(a,min(b,min(c,min(d,e))));

  time=(n+mini-1)/mini;

  movetime=time+4;


  cout << movetime << endl;

}
