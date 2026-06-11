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

vector<ll> bunkai(ll a){
  if(a<=0) return {};
  if(a==1) return {{1,1}};
  vector<ll> f;
  ll b=a;
  for(ll i=2;i*i<=a;i++){
    if(b%i==0){
      f.push_back(i);
      b=b/i;
      i--;
    }
  if(b==1)break;
  }
  if(b!=1)f.push_back(b);

  return f;
}

int main(){

  ll n;
  cin >> n;

  vec a;
  vector<bool> b(600000);
  for(ll i=2;i<=500000;i++){
    vec v=bunkai(i);
    if(v.size()==1){
      a.push_back(i);
      b[i]=1;
    }
  }

  //cout << 5 << endl;

  vec ans;
  ll p=0;
  for(ll i=0;i<a.size();i++){
    if(a[i]%10==1)ans.push_back(a[i]);
  }
  
  for(ll i=0;i<n;i++)cout << ans[i] << " ";
  cout << endl;


}