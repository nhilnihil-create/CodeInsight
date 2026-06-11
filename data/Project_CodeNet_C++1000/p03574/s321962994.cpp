#include <bits/stdc++.h>
using namespace std;

int main() {
  
  //初期宣言
  int H,W;
  //HとWを読み込み
  cin >> H >>W;

  //H×Wのdataとout用の行列を定義する
  vector<vector<char>>data(H,vector<char>(W));
  
  for(int i = 0; i < H; i++ ){
    for(int j = 0; j < W; j++){
		cin >> data.at(i).at(j);      
    }
  }
  
  //判定用
  for(int i = 0; i < H; i++ ){
        
    for(int j = 0; j < W; j++){
       
       //地雷かどうかの判定
       if( data.at(i).at(j) == '#'){
         cout << '#' ;
       }
       
       //地雷出ない場合の周りの地雷の数を数えるプログラム
       else if( data.at(i).at(j) == '.' ){
         
         //回答用のdataを宣言
         int A=0;
               
      	//左上用
		if(i != 0 && j != 0){
          if(data.at(i-1).at(j-1)=='#'){
           	A++; 
          }
        }
         
        //真ん中上用
		if(i != 0){
          if(data.at(i-1).at(j)=='#'){
           	A++; 
          }
        }
         
        //右上用
		if(i != 0 && j != W-1){
          if(data.at(i-1).at(j+1) == '#'){
           	A++; 
          }
        }
         
        //左横用
		if(j != 0){
          if(data.at(i).at(j-1) == '#'){
           	A++; 
          }
        }
         
        //右横用
		if(j != W-1){
          if(data.at(i).at(j+1)=='#'){
           	A++; 
          }
        }
         
        //左下用
		if(i != H-1 && j != 0){
          if(data.at(i+1).at(j-1) == '#'){
           	A++; 
          }
        }
         
        //真ん中下用
		if(i != H-1){
          if(data.at(i+1).at(j) == '#'){
           	A++; 
          }
        }
        
        //右下用
		if(i != H-1 && j != W-1){
          if(data.at(i+1).at(j+1) == '#'){
           	A++; 
          }
        }
         
        //結果を出力 
        cout << A ;
       }
      
     else{
       cout << "error" << endl;
     }
      
    }
    //改行用
    cout << endl;
  }
  
  
}
