#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;

int main(){
  int R,G,B,n;
  cin >> R >> G >> B >> n;
  int64_t ans =0 ;
  for(int i=n/R;i>=0;i--){
    for(int j=(n-i)/G;j>=0;j--){
      if((n-R*i-G*j)>=0&&(n-R*i-G*j)%B==0) ans++;
    }
  }
  cout << ans << endl;
}