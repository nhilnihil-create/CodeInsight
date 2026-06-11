#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

bool kaibun(ll a){
  string s=to_string(a);
  ll n=s.size();
    bool ok=true;
    for(ll i=0;i<n/2;i++)if(s[i]!=s[n-1-i])ok=0;
    if(ok)return 1;
    else return 0;
}

int main(){

  ll a,b;
  cin >> a >> b;

  ll ans=0;
  for(ll i=a;i<=b;i++)if(kaibun(i))ans++;

  cout << ans << endl;

}