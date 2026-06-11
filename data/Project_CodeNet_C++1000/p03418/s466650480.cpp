#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int main(){
  int n,k; cin >> n >> k;
  ll cnt = 0;
  
  for(int b=1;b<=n;b++){
    cnt += n/b * max(b-k,0);
    cnt += max(n%b-(k-1),0);
    if(k==0) cnt--;
    //printf("b=%d cnt=%d\n",b,cnt);
  }
  
  cout << cnt << endl;
  return 0;
}