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

ll ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

int main(){

  string s;
  cin >> s;
  for(ll i=0;i<3;i++){
    ll a=ctoi(s[i]);
    cout << 10-a;
  }
  cout << endl;

}