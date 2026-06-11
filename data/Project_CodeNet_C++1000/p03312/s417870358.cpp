#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000000000005LL
#define MOD 1000000007
 
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
 
int N;
ll A[SIZE];
ll S[SIZE];
 
int main(){
  cin >> N;
  rep(i,0,N){
    cin >> A[i];
    S[i] = A[i];
  }
  rep(i,0,N-1){
    S[i+1] += S[i];
  }
 
  ll ans = INF;
 
  int l=0,r=2;
  rep(t,1,N-2){
    while(abs(S[t]-2*S[l]) > abs(S[t]-2*S[l+1]))l++;
    while(abs(S[N-1]-2*S[r]+S[t]) > abs(S[N-1]-2*S[r+1]+S[t]))r++;
    ans = min(ans, max({S[l],S[t]-S[l],S[N-1]-S[r],S[r]-S[t]})
      - min({S[l],S[t]-S[l],S[N-1]-S[r],S[r]-S[t]}));
  }
  cout << ans << endl;
 
 
  return 0;
}