#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
typedef long long int ll;
const int MOD=1000000007;
using Graph = vector<vector<int>>;
using ipair = pair<ll,ll>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  int n;cin>>n;
  priority_queue<ipair, std::vector<ipair>, std::less<ipair>> que1,que2;
  vector<ll> u(100002,0),v(100002,0);
  rep(i,n){
    ll num;cin>>num;
    if(i%2==0){
      v[num]++;
    }
    else{
      u[num]++;
    }
  }
  rep(i,100002){
    que1.push(make_pair(v[i],i));
    que2.push(make_pair(u[i],i));
  }
  ll ans = n;
  ipair q11,q12,q22,q21;
  q11=que1.top();q21=que2.top();
  que1.pop();que2.pop();
  q12=que1.top();q22=que2.top();
  if(q11.second!=q21.second){
    ans -= q11.first;
    ans -= q21.first;
  }
  else {
    ll mx = max(q12.first+q21.first,q11.first+q22.first);
    ans -= mx;
  }

  cout<<ans;
  return 0;
}