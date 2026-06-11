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

int main(){

  ll n;
  string s;
  cin >> n >> s;

  ll ans=0;
  for(ll i=1;i<n-1;i++){
    string t=s.substr(0,i+1),u=s.substr(i+1);
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(),t.end()),t.end());
    ll k=0;
    for(ll j=0;j<t.size();j++){
      for(ll l=0;l<u.size();l++){
        if(t[j]==u[l]){
          k++;
          break;
        }
      }
    }
    ans=max(ans,k);
  }

  cout << ans << endl;

}