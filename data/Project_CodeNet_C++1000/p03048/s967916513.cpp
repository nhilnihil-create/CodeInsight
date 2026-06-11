#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(void)
{
  ll R,G,B,N;
  cin >>R>>G>>B>>N;
  ll ans=0;
  for(ll r=0;r*R<=N;r++) {
    for(ll g=0;g*G<=N;g++) {
      ll bn=N-r*R-g*G;
      if(bn>=0&&bn<=N&&bn%B==0){
        ans++;
      }
    }
  }
  cout << ans << endl;
}