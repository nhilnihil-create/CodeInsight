#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,ll>;
const ll inf=1000000000007;
const int mod=1000000007;


vector<int> Parent;

class UnionFind {
public:
	//親の番号を格納する。親だった場合は-(その集合のサイズ)
//	vector<int> Parent;
 
	//作るときはParentの値を全て-1にする
	//こうすると全てバラバラになる
	UnionFind(int N) {
		Parent = vector<int>(N, -1);
	}
 
	//Aがどのグループに属しているか調べる
	int root(int A) {
		if (Parent[A] < 0) return A;
		return Parent[A] = root(Parent[A]);
	}
 
	//自分のいるグループの頂点数を調べる
	int size(int A) {
		return -Parent[root(A)];//親をとってきたい]
	}
 
	//AとBをくっ付ける
	bool connect(int A, int B) {
		//AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
		A = root(A);
		B = root(B);
		if (A == B) {
			//すでにくっついてるからくっ付けない
			return false;
		}
 
		//大きい方(A)に小さいほう(B)をくっ付けたい
		//大小が逆だったらひっくり返しちゃう。
		if (size(A) < size(B)) swap(A, B);
 
		//Aのサイズを更新する
		Parent[A] += Parent[B];
		//Bの親をAに変更する
		Parent[B] = A;
 
		return true;
	}
};



int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n,-1);

  UnionFind Uni(n);

  rep(i,0,m){
    int x,y,z;
    cin >> x >> y >> z;
    x--; y--;
    Uni.connect(x,y);
}
  int cnt=0;
  rep(i,0,n){
    if(Parent[i]<0){
      cnt+=1;
    }
//    cout << Parent[i] << endl;
  }
  cout << cnt << endl;
  return 0;
}