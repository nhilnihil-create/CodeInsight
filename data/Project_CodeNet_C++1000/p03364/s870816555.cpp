#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

class RollingHash{
  public:
  vector<vector<ull>> hash1,hash2;
  vector<ull> pows;
  vector<string> s;
  const int n;
  const ull base = 1162261467;
  const ull modu = (1ll << 61)-1;
  const ull msk = (1ll << 31)-1;
  RollingHash(int N,vector<string> k): hash1(2*N+1,vector<ull>(2*N+1,0)),hash2(2*N+1,vector<ull>(2*N+1,0)),pows(2*N+1,1),n(N),s(k) {
    rep(j,2*n)rep(i,2*n)hash1[j][i+1] = mod(mul(hash1[j][i],base)+s[j][i]);
    rep(j,2*n)rep(i,2*n)hash2[j][i+1] = mod(mul(hash2[j][i],base)+s[i][j]);
    rep(i,2*n)pows[i+1] = mod(mul(pows[i],base));
  }
  vector<ull> get(ll uy,ll ux,bool is){
    vector<ull> res(n);
    if(is){
      rep(i,n)res[i] = mod(modu*3+hash1[uy+i][ux+n]-mul(hash1[uy+i][ux],pows[n]));
    }else{
      rep(i,n)res[i] = mod(modu*3+hash2[ux+i][uy+n]-mul(hash2[ux+i][uy],pows[n]));
    }
    return res;
  }
  ull mul(ll l,ll r){
    ull ul = l >> 31,dl = l & msk;
    ull ur = r >> 31,dr = r & msk;
    ull um = (ul*dr+dl*ur) >> 31,dm = (ul*dr+dl*ur) & msk;
    return ul*ur*2 + dl*dr + (um << 1) + (dm << 31);
  }
  ull mod(ll val){
    ull u = val >> 61,d = val & modu;
    return u+d >= modu ? u+d-modu  : u+d;
  }
};

int main(){
  
  int n;
  cin >> n;
  vector<string> s(2*n);
  rep(i,n)cin >> s[i];
  rep(i,n)s[i] += s[i];
  rep(i,n)s[n+i] = s[i];
  RollingHash rh(n,s);
  ll res = 0;
  rep(i,n)rep(j,n){
    if(rh.get(i,j,true) == rh.get(i,j,false))res++;
    //vector<ull> g = rh.get(i,j,true),gg = rh.get(i,j,false);
    //rep(k,n)cout << g[k] << " ";cout << endl;
    //rep(k,n)cout << gg[k] << " ";cout << endl;
    //cout << endl;
  }

  cout << res << endl;
  /*
  rep(i,2*n)rep(j,2*n)cout << rh.hash1[i][j] << (j == 2*n-1 ? "\n" : " ");
  cout << endl;
  rep(i,2*n)rep(j,2*n)cout << rh.hash2[i][j] << (j == 2*n-1 ? "\n" : " ");
  
  cout << rh.mod((rh.modu*4+rh.hash1[2][3+n]-rh.mul(rh.hash1[2][3],rh.pows[n]))) << endl;
  cout << rh.mod((rh.modu*4+rh.hash2[3][2+n]-rh.mul(rh.hash2[3][2],rh.pows[n]))) << endl;*/


  return 0;
}