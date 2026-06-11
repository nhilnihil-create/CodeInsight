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

  ll n,y;
  cin >> n >> y;

  for(ll i=0;i<2001;i++){
    for(ll j=0;j<2001;j++){
      if(i+j>n)continue;
      if(10000*i+5000*j+1000*(n-i-j)==y){
        cout << i << " " << j << " " << n-i-j <<  endl;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;

}