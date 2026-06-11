#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;
  int n = 0;
  //nは２で割れる回数
  
  	for (int i = 0; i < N; i++){
      int x;
      cin >> x;
      int sub = 0;//subは入力された数単体が２で割れる回数
	   	
      for (int j = 0; ; j++){
          if ( x % 2 ==0){
            sub ++;
            x /=2;
          }
          else 
            break;
    	}
      
      if(i == 0)
        n = sub;//１回目

      else if(n > sub)
        n = sub;//２回目以降；nを小さい方に書き換え

    }//ここまでfor文
   cout << n << endl;
}