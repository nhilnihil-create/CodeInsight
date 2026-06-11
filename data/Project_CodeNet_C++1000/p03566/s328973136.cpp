#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int t[210],v[210];

int main(){
  int n;
  cin >> n;
  rep(i,n) cin >> t[i];
  rep(i,n) cin >> v[i];
  
  double ret = 0, sp = 0;
  rep(i,n){
    for(double j=0; j<t[i]; j += 0.5){
      bool flag1 = true, flag2 = true;
      double ti = t[i]-j-0.5;
      for(int k = i+1; k<n;k++){
        ti += t[k];
        if(sp+0.5-ti > v[k+1]) flag1 = false;
        if(sp-v[k+1] > ti) flag2 = false;
      }
      if(sp+0.5 <= v[i] && flag1 && (sp+0.5-(t[i]-j-0.5)) <= v[i+1]){
        ret += sp*0.5;
        ret += 0.125;
        sp += 0.5;
      }else if(sp-v[i+1] <= t[i]-j-0.5 && flag2){
        ret += sp*0.5;
      }else{
        sp -= 0.5;
        ret += sp*0.5;
        ret += 0.125;
      }
    }
  }
  
  printf("%.15f\n",ret);
  return 0;
}