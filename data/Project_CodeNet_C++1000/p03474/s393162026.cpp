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

  ll a,b;
  string s;
  cin >> a >> b >> s;

  bool ok=true;
  for(ll i=0;i<a;i++){
    if('0'<=s[i] && s[i]<='9');
    else ok=false;
  }
  if(s[a]=='-');
  else ok=false;
  for(ll i=a+1;i<a+b+1;i++){
    if('0'<=s[i] && s[i]<='9');
    else ok=false;
  }

  if(ok)cout << "Yes" << endl;
  else cout << "No" << endl;

}