#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  string s;
  cin >> s;

  ll ans=inf;
  for(ll i=0;i<s.size()-2;i++){
    string t=s.substr(i,3);
    ans=min(ans,abs(753-stoll(t)));
  }
  cout << ans << endl;

}