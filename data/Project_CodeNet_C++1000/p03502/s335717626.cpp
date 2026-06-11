#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, i, B, digit = 1, sum = 0, C;
  cin >> N;
  
  B = N; // Nのバックアップ
  C = N; // Nのバックアップ

  //N の桁数
  
 for ( i = 0; i < N; i++) { 
   if (B / 10 > 0) {
     B = B / 10;
     digit++;
   }
   else {
     break;
   }
}

  //Nの数字一覧
  
   for ( i = 0; i < digit; i++) { 
	sum += N % 10;
     N /= 10;
   }
 
  if( C % sum == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  
}