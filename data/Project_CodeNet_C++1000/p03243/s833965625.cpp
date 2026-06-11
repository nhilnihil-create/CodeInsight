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

bool ok(ll a){
  string s=to_string(a);
  if(s[0]==s[1] && s[1]==s[2])return 1;
  else return 0;
}

int main(){

  ll n;
  cin >> n;

  while(!ok(n))n++;

  cout << n << endl;



}