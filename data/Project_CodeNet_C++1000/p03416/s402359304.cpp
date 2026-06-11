#include<bits/stdc++.h>
using namespace std;

int main(void){
  int a, b;
  cin >> a >> b;
  
  int wa = 0;
  for( int i = a ; i < b+1 ; i++ ){
    int c[4];
    c[0] = i / 10000;		//5ケタ目の数の抽出
    c[1] = i % 10;			//1ケタ目の数の抽出    
    c[2] = i / 1000 % 10;	//4ケタ目の数の抽出
    c[3] = i % 100 / 10;	//3ケタ目の数の抽出
//    cout << c[0] << "  " << c[2] << " ? "  << c[3] << "  "  << c[1] << "  " << endl;
    if( c[0] == c[1] ){
      if( c[2] == c[3] ){
        wa++;
      }
    }
  }
  cout << wa << endl;
}