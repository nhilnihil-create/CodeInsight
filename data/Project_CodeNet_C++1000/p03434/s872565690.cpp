#include <bits/stdc++.h>
using namespace std;
int main (){
  int N; //データの数
  cin >> N;
  
  int data1=0,data2=0;//AliceとBobの点数
  
  vector <int> a(N);
  
  for(int i=0;i<N;i++)
    cin >>a.at(i);//データの収納
  
  sort(a.begin(),a.end());//小さい順に並べ替え
  reverse(a.begin(),a.end());//順番を逆にする（大きい順に変更）
  
  for(int i=0;i<N;i++){
    if(i%2 == 0)
      data1 += a.at(i);//aliceのデータ
      
    if(i%2 == 1)
      data2 += a.at(i);//Bobのデータ
  }
  cout << data1 -data2 <<endl;//出力部
}

