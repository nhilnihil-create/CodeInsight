#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 100010

/*
Union Find Tree

何回でもスワップできるので、
スワップできるのもの同士を同じグループにする
同じグループだったら好きなところに移動できるって証明できる・・・？？
直感的にはできるぽい
*/

int par[MAX_N];//親の番号
int rnk[MAX_N];//ランク

void init(int n)
{
  //根の定義・・・par[i]=iの時iを根という
  //最初全てが根
  for (int i=0;i<n;i++){
    par[i]=i;
    rnk[i]=0;
  }
}

//木の根を求める
int root(int x){
  if (par[x]==x){  //xが根の時
    return (x); 
  }else{
    par[x]=root(par[x]);//xを、xの親の根につなぎ直す
    return par[x]; //経路圧縮
  }
}

//x,yが同じ集合に属しているか、つまり同じ根に繋がっているか
bool same(int x,int y){
  return ( root(x)==root(y) );
}

//x,yの属する集合を合併する
bool merge(int x, int y) {
   x = root(x); y = root(y);
   if (x == y) return false;
   if (rnk[x] < rnk[y]) swap(x, y);
   if (rnk[x] == rnk[y]) rnk[x]++;
   //ランクがxの方が大きい時はrnk[x]に変わりがないが、同じ時は変わるので++が必要
   par[y] = x; //ランクが大きい方に小さい方を繋げる
   return true;
}

int main()
{
  int N,M;cin>>N>>M;
  vector<ll> p(N+1);
  for (int i=1;i<=N;i++)
    cin>>p[i];
  
  init(N);
  
  for (int i=1;i<=M;i++)
  {
    int x,y;cin>>x>>y;
    //p[x],p[y]はスワップできるので同じグループに
    merge(p[x],p[y]);
  }
  
  int count=0;
  for (int i=1;i<=N;i++)
  {
    //p[i],iが同じ木にいたら、p[i]はi番目に移動できる
    if (same(p[i],i)) count++;
  }
  cout<<count<<endl;
}