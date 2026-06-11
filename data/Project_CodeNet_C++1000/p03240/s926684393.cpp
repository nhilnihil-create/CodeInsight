#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int x[N], y[N], h[N];
  for(int i=0; i<N; i++)
    cin >> x[i] >> y[i] >> h[i];
  //入力終わり

  int H;
  int cx, cy;

  int tmpH;
  //center座標の全探索
  for(cx=0; cx<=100; cx++){
    for(cy=0; cy<=100; cy++){
      //全ての点からHを全探索で計算
      for(int i=0; i<N; i++){
	//その点の高さが0ならHとの関連性はない
	if(h[i] == 0)
	  continue;

	//0でない高さからHを計算できたら一回roopを出る
	H = h[i] + abs(x[i]-cx) + abs(y[i]-cy);
	break;
	
      } //i roop

      //上で求めたHに対して，任意の点で条件を満たすか確かめる
      bool flag = true;
      for(int i=0; i<N; i++){
	//満たさなければ次のループへ
	if(h[i] != max(H - abs(cx-x[i] ) - abs(cy-y[i] ), 0 ) ){
	  flag = false;
	  break;
	}
      }
      
      if(flag)
	goto end;
    } //cy roop
  } //cx roop

 end :

  cout << cx << " " << cy << " " << H << endl;

  return 0;
}
