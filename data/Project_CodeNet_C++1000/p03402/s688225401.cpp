#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int main(){
  int a,b; cin >> a >> b;
  vector<string> s(100);
  rep(i,100)rep(j,100){
    if(j<50) s[i] += "#";
    else s[i] += ".";
  }
  
  a--; b--;
  rep(j,25)rep(i,50){
    if(a>0){
      s[2*i][2*j]='.';
      a--;
    }
  }
  rep(j,25)rep(i,50){
    if(b>0){
      s[2*i][99-2*j]='#';
      b--;
    }
  }

  printf("%d %d\n",100,100);
  rep(i,100){
    cout << s[i] << endl;
  }
  
  return 0;
}