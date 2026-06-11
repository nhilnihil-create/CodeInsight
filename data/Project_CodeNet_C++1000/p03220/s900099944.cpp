#include <bits/stdc++.h>
using namespace std;

double Temp (int T_Normal,int Height){
  double T;
  T = T_Normal - 0.006*Height;
  return T;
}

  
int main() {
  //入れ物の宣言
  int N ; //データの数
  int T_Normal ; //平均気温
  int T_Stand ; //基準温度
  int Num = 0 ; //ベストな番地(0を代入）
  vector<int> height(1500); //各地点の標高
  
  //データ入力部
  cin >> N ;
  cin >> T_Normal;
  cin >> T_Stand ;
  
  for (int i = 0;i < N; i++){
    cin >> height.at(i);
  }
  
  //一番基準の温度に近いところを検索
   
  for (int i =1 ; i < N;i++){
    if (abs(T_Stand - Temp(T_Normal,height.at(Num))) > abs(T_Stand - Temp(T_Normal,height.at(i)))){
      Num = i;
    }
  }
   
 cout << Num + 1 << endl;
}