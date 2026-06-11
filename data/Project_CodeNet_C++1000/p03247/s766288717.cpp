#include <bits/stdc++.h>
using namespace std;

int n,x[1000],y[1000],u[1000],v[1000];

int main(){
  cin >> n;
  for(int i=0;i<n;i++) cin >> x[i] >> y[i];

  // 目的地の座標和の偶奇が一致しているか確かめる
  bool ok = true;
  int p = abs(x[0] + y[0]) % 2;
  for(int i=1;i<n;i++){
    if( p != abs(x[i]+y[i]) % 2 ) ok = false;
  }

  if(ok){
    // 座標変換を行う
    for(int i=0;i<n;i++){
      v[i] = x[i] + y[i];
      u[i] = x[i] - y[i];
    }

    // 2進数 2^30,...4,2,1を用いて目的地の座標和を作成する
    // 腕の長さ(di)を用意 目的地の座標和が偶数->さらに1を足す
    vector<int> d;
    for(int i=30;i>=0;i--) d.push_back(1<<i);
    if( p == 0 ) d.push_back(1);
    cout << d.size() << endl;
    for(int i=0;i<d.size();i++){
      if(i) cout << " ";
      cout << d[i];
    }
    cout << endl;

    // 目的地ごとに大きい方の腕から方向を決める
    for(int i=0;i<n;i++){
      int vp = 0, up = 0;
      int x2 = 0, y2 = 0;
      for(int j=0;j<d.size();j++){
        if(vp <= v[i]){
          if(up <= u[i]){
            cout << "R";
            x2 += d[j];
            vp += d[j];
            up += d[j];
          }else{
            cout << "U";
            y2 += d[j];
            vp += d[j];
            up -= d[j];
          }
        }else{
          if(up <= u[i]){
            cout << "D";
            y2 -= d[j];
            vp -= d[j];
            up += d[j];
          }else{
            cout << "L";
            x2 -= d[j];
            vp -= d[j];
            up -= d[j];
          }
        }
      }
      cout << endl;
    }
  }
  else { cout << -1 << endl; return 0; }
  return 0;
}
