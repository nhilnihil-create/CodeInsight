#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;

class UnionFind{
public:
    //親の番号を格納する。親だった場合は-(その集合のサイズ)
    vector<int> Parent;

    //作る時はParentの値を全て-1にする
    //こうするとずべてバラバラになる
    UnionFind(int N){
      Parent = vector<int>(N,-1);
    }

    //Aがどのグループに属しているのか調べる
    int root(int A){
      if(Parent[A]<0) return A;
      return Parent[A] = root(Parent[A]);
    }

    //自分のいるグループの頂点数を調べる
    int size(int A){
      return -Parent[root(A)];//親を取ってきたい
    }

    //AとBをくっつける
    bool connect(int A,int B){
      //AとBを直すつつなぐのではなく、root(A)にroot(B)をくっつける)
      A = root(A);
      B = root(B);
      if(A==B){
        //すでにくっついているからくっつけない
        return false;
      }
      //大きい方(A)に小さい方(B)をくっつけたい
      //大小が逆だったらひっくり返しちゃう
      if(size(A)<size(B)) swap(A,B);

      //Aのサイズを更新する
      Parent[A] += Parent[B];
      //Bの親をAに変更する
      Parent[B] = A;

      return true;
    }
  };


int main(){
  ll N , M; cin >> N >> M;
  vector<P> a(M); rep(i,M) cin >> a[i].fi >> a[i].sc;
  rep(i,M) { a[i].fi--; a[i].sc--;}

  UnionFind Uni(N);
  vector<ll> ans(M);
  ans[M - 1] = N *(N - 1) / 2;

  for(ll i = M - 1; i > 0; i--){
    // 後ろからつなげていく
    if(Uni.root(a[i].fi) == Uni.root(a[i].sc) ){
      Uni.connect(a[i].fi , a[i].sc);
      ans[i - 1] = ans[i];
    }
    else{
      ans[i - 1] = ans[i] - Uni.size(a[i].fi) * Uni.size(a[i].sc);
      Uni.connect(a[i].fi , a[i].sc);
    }
  }

  rep(i,M) cout << ans[i] << endl;

}
