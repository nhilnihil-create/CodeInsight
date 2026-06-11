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

ll dist(vec a,vec b){
  return abs(a[0]-b[0])+abs(a[1]-b[1]);
}

int main(){

  ll h,w,d;
  cin >> h >> w >> d;

  mat l(h*w+1);
  for(ll i=0;i<h;i++){
    for(ll j=0;j<w;j++){
      ll a;
      cin >> a;
      l[a]={i,j};
    }
  }

  //cout << 5 << endl;



  vector<vector<ll>> s(d+1,vec(h*w/d+10,0));
  for(ll i=1;i<=d;i++){
    for(ll j=0;i+d*(j+1)<=h*w;j++){
      s[i][j+1]=s[i][j]+dist(l[i+d*j],l[i+d*(j+1)]);
    }
  }

  ll q;
  cin >> q;

  vec ans;

  //cout << 5 << endl;

  for(ll i=0;i<q;i++){
    ll u,v;
    cin >> u >> v;
    ll y=u%d;
    if(y==0)y=d;
    ll x=(u-y)/d;
    ll z=(v-y)/d;
    ans.push_back(s[y][z]-s[y][x]);
    //cout << s[y][z] << " " << s[y][z] << endl;
  }

  for(ll i=0;i<ans.size();i++)cout << ans[i] << endl;

  //for(ll i=0;i<6;i++)cout << s[2][i] << endl;

}