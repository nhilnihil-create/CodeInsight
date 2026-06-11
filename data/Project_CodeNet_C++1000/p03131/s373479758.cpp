#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;

int main(void){
  ll k,a,b; cin >> k >> a >> b;
  ll ans;
  if(b-a<=2){
    ans = k+1;
  }else{
    k-=a-1;
    ans = a + (b-a)*(k/2) + k%2;
  }

  cout << ans << endl;
}
