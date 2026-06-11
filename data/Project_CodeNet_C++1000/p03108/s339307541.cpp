#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)

#ifdef LOCAL//compile with -DLOCAL
#define debug(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<(x)<<endl
#define debug_vec(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = ";\
  rep(i,sz(x)){cerr<<x[i]<<" ";}cerr<<endl
#define debug_mat(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<endl;\
  rep(i,sz(x)){rep(j,sz(x[i])){cerr<<x[i][j]<<" ";}cerr<<endl;}cerr<<endl
#else
#define debug(x) void(0)
#define debug_vec(x) void(0)
#define debug_mat(x) void(0)
#endif

template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

class Union_Find_size{
public:
  vector<int> Parent;
  //コンストラクタ
  Union_Find_size(int N){
    Parent=vector<int>(N,-1);
  }
  //木の根を求める
  int root(int x){
    //x（自分）が親ならxを返す
    if(Parent.at(x)<0)  return x;
    //経路圧縮しながら return する
    return Parent.at(x)=root(Parent.at(x));
  }
  //xの属する木の要素数を調べる
  int size(int x){
    return -Parent.at(root(x));
  }
  //xとyが同じ集合に属するかを判定する
  bool same(int x,int y){
    return root(x)==root(y);
  }
  //xとyの属する集合を併合する
  void unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)  return;
    if(size(x)<size(y)) swap(x,y);
    Parent.at(x)+=Parent.at(y);
    Parent.at(y)=x;
  }
};

//abc097d,abc120d,abc126e

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  ll N,M;
  cin >> N >> M;
  vector<int> A(M),B(M);
  rep(i,M){
    cin >> A.at(i) >> B.at(i);
    A.at(i)--;
    B.at(i)--;
  }
  reverse(all(A));
  reverse(all(B));

  vector<ll> ans(M,-1);
  ll now=N*(N-1)/2;
  ans.at(0)=now;
  Union_Find_size uni(N);
  rep(i,M-1){
    if(!uni.same(A.at(i),B.at(i))){
      int a=uni.size(A.at(i));
      int b=uni.size(B.at(i));
      now-=a*b;
      uni.unite(A.at(i),B.at(i));
    }
    ans.at(i+1)=now;
  }
  reverse(all(ans));
  rep(i,M)  cout << ans.at(i) << endl;

  return 0;
}