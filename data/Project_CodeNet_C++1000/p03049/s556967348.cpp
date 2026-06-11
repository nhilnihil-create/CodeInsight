#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<endl
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define mp make_pair
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define sz(x) (int)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pll = pair<ll, ll>;
using vc = vector<char>;
using vvc = vector<vc>;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll n;
  cin>>n;
  vstr s(n);
  ll ans=0;
  ll r=0;
  ll l=0;
  ll rl=0;
  rep(i,n){
    cin>>s[i];
    for(int j=0;j<sz(s[i])-1;j++){
      if(s[i][j]=='A'&&s[i][j+1]=='B') ans++;
    }      
    if(s[i][0]=='B'&&s[i][sz(s[i])-1]=='A'){
      rl++;
    }
    else if(s[i][sz(s[i])-1]=='A'){
      r++;
    }
    else if(s[i][0]=='B'){
      l++;
    }
  }
  if(rl>0){
    ans+=rl-1;
    rl=1;
  }
  if(r>0&&l>0&&rl==1){
    ans+=2;
    r--;
    l--;
    rl--;
  }
  
    ans+=min(r,l);
    r-=min(r,l);
    l-=min(r,l);
  
  if(r>0||l>0){
    if(rl>0){
      ans++;
    }
  }
  COUT(ans);
}
