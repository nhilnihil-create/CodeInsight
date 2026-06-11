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

  string s,t;
  cin >> s >> t;

  sort(s.begin(),s.end());
  sort(t.begin(),t.end());

  ll n=s.size();
  vec u,v;
  ll c=1;
  char r=s[0];
  for(ll i=1;i<n;i++){
    if(r==s[i]){
      c++;
    }
    else{
      r=s[i];
      u.push_back(c);
      c=1;
    }
  }
  u.push_back(c);
  c=1;
  r=t[0];
  for(ll i=1;i<n;i++){
    if(r==t[i]){
      c++;
    }
    else{
      r=t[i];
      v.push_back(c);
      c=1;
    }
  }
  v.push_back(c);
  sort(u.begin(),u.end());
  sort(v.begin(),v.end());

  if(u==v)cout << "Yes" << endl;
  else cout << "No" << endl;

}