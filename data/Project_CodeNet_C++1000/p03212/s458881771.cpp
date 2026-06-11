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

ll powmod(ll a,ll n,ll m) {
    if(n == 0)
        return 1;

    if(n % 2 ==0){
        ll r = powmod(a,n/2,m);
        return r*r % m;
    }

    return a*powmod(a,n-1,m)%m;
}

ll factmod(ll a,ll b,ll m) {
  if(a<b)return 0;
  ll s=1;
  while(a>=b){
    s = s*a % m;
    a -= 1;
  }
  return s;
}

ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

ll combmod(ll a,ll b,ll m){
  if(b==0)return 1;
  ll c=factmod(a,a-b+1,m);
  ll d=modinv(factmod(b,1,m),m);
  ll e=(c*d)%m;
  return e;
}

void modsum(ll &a,ll b,ll m){
  a+=b;
  a%=m;
}

void modsub(ll &a,ll b,ll m){
  a-=b;
  a+=m;
  a%=m;
}

void modmul(ll &a,ll b,ll m){
  a*=b;
  a%=m;
}

void modquo(ll &a,ll b,ll m){
  a*=modinv(b,m);
  a%=m;
}

ll ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

int main(){

  ll n;
  cin >> n;

  ll ans=0;

  queue<ll> q;
  q.push(3);
  q.push(5);
  q.push(7);

  vec v={3,5,7};
  while(!q.empty()){
    ll a=q.front();
    q.pop();
    for(ll i=3;i<=7;i+=2){
      if(a*10+i<=1000000000){
        v.push_back(a*10+i);
        q.push(a*10+i);
      }
    }
  }

  vec u;
  for(ll i=0;i<v.size();i++){
    ll a[13]={};
    string s=to_string(v[i]);
    for(ll j=0;j<s.size();j++){
      a[ctoi(s[j])]++;
    }
    if(a[3]>0 && a[5]>0 && a[7]>0)u.push_back(v[i]);
  }

  sort(u.begin(),u.end());

  ans=upper_bound(u.begin(),u.end(),n)-u.begin();

  cout << ans << endl;




}