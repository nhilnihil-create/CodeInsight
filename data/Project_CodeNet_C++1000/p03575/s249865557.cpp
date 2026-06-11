#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 200010

/*
辺が橋である⇔その辺がないとグラフが非連結になる
辺の個数はM個で50個以下なので
全探索してみてもいい気がする・・・

なんかバグると思って
ずっと悩んでたら入力が無限にされると思ってたwww
最初に入力保存してなきゃダメでしょ、初歩的なミス
*/

int par[MAX_N];//親の番号
int siz[MAX_N];//木のサイズ
//int rnk[MAX_N];

void init(int n)
{
  //根の定義・・・par[i]=iの時iを根という
  //最初全てが根
  for (int i=0;i<=n;i++){
    par[i]=i;
    siz[i]=1;
  }
}

//木の根を求める
int root(int x)
{ 
  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
  if (par[x] == x) return x;
  else{
    return par[x]=root(par[x]); 
  }
}

//x,yが同じ集合に属しているか、つまり同じ根に繋がっているか
bool same(int x,int y){
  return ( root(x)==root(y) );
}

//x,yの属する集合を合併する
bool merge(int x, int y) {
  x=root(x);
  y=root(y);
  if (x==y) return false;
  par[y]=x;
  return true;
}

int treesize(int x)
{
  return (siz[root(x)]); 
}

int main()
{
  int N,M;cin>>N>>M;
  
  //i番目の辺がない時を考える
  //辺が全部ある時は連結グラフなので非連結になったらカウント
  int count = 0;
  
  vector<int> a(M+1),b(M+1);
  for (int i=1;i<=M;i++)
    cin>>a[i]>>b[i]; 
  
  for (int i=1;i<=M;i++)
  {
    //i番目の辺がなかった時のグラフを考える
    init(N);//UnionFind初期化
    
    for (int j=1;j<=M;j++)
    {
      if (j!=i) merge(a[j],b[j]);
    }
    
    map<int,int> m;
    for (int j=1;j<=N;j++)
    {
      m[root(j)]++;
      //cout<<"root("<<j<<")="<<root(j)<<endl;
    }
  
    if (m.size()>=2)
    {
      //cout<<"橋の番号:"<<i<<endl;
      count++;//橋をカウント
    }
  }
  cout<<count<<endl;
} 
