#include <bits/stdc++.h>
#define rep(var,cnt) for(int (var)=0; (var)<(int)(cnt); ++(var))
#define REP(var,init,cnt) for(int (var)=(init); (var)<(cnt); ++(var))
#define ran(var,vec) for(auto &(var):(vec))
#define all(v) (v).begin(),(v).end()
#define TF(flag) (flag)?1:0
#define fi first
#define se second
#define debug if(DEBUG)
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using pi = pair<int,int>;
 
template<typename T>
using vec = vector<T>;
template<typename T>
using mat = vector<vec<T>>;
 
template<typename T1,typename T2>
ostream &operator<<(ostream &os, const pair<T1,T2> &p){
  os<<"P("<<p.first<<", "<<p.second<<") ";
  return os;
}
 
template<typename T1,typename T2>
istream &operator>>(istream &is, pair<T1,T2> &p){
  is>>p.first>>p.second;
  return is;
}
 
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
  for(int i=0; i<(int)v.size(); ++i){
    os<<v[i]<<(i+1!=v.size()?" ":"");
  }
  return os;
}
 
template<typename T>
istream &operator>>(istream &is, vector<T> &v){
  for(T &in:v) is>>in;
  return is;
}
 
bool DEBUG=true;

int main(void){
  int N; cin>>N;
  mat<char> S(N,vec<char>(N));
  rep(i,N){
    rep(j,N){
      cin>>S[i][j];
    }
  }
  
  int ans=0;
  rep(A,N){
    bool able=true;
    rep(i,N){
      rep(j,N){
        able=able&&(S[i][j]==S[j][i]);
      }
    }
    ans+=TF(able);
    S.insert(S.begin(),S[N-1]);
    S.pop_back();
  }
  cout<<ans*N<<endl;
}