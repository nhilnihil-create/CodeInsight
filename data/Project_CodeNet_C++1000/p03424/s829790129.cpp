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
  cin >> n;
  vector<char> s(n);
  for(ll i=0;i<n;i++)cin >> s[i];
  sort(s.begin(),s.end());
  s.erase(unique(s.begin(),s.end()),s.end());

  //cout << s.size() << endl;
  //for(ll i=0;i<4;i++)cout << s[i] << endl;

  if(s.size()==4)cout << "Four" << endl;
  else cout << " Three" << endl;
}