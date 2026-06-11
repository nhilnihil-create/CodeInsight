#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265359
#define MOD 998244353
const int MAX = 510000;

int main() {
  int N;cin>>N;
  map<char,ll> score;
  rep(i,N){
   string s;
   cin>>s;
   char q=s[0]; 
   if(q=='M'||q=='A'||q=='R'||q=='C'||q=='H'){
   score[q]++;}
  }
  ll m[5];
  m[0]=score['M'];
  m[1]=score['A'];
  m[2]=score['R'];
  m[3]=score['C'];
  m[4]=score['H'];
  ll ans=0;
  ans+=m[0]*m[1]*m[2];
  ans+=m[0]*m[1]*m[3];
  ans+=m[0]*m[1]*m[4];
  ans+=m[0]*m[2]*m[3];
  ans+=m[0]*m[2]*m[4];
  ans+=m[0]*m[3]*m[4];
  ans+=m[1]*m[2]*m[3];
  ans+=m[1]*m[2]*m[4];
  ans+=m[1]*m[3]*m[4];
  ans+=m[2]*m[3]*m[4];
  cout<<ans;
}