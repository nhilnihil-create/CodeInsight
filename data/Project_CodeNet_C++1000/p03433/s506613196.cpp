#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; //支払う金額
  int A; //所持している1円玉の枚数
  
  cin >> N;
  cin >> A;
  
  int B = N / 500; //500円玉を何枚使うか
  int C = N - B * 500; //1円で払う金額
    
  if (C <= A){
  	cout << "Yes" << endl;
  }else{
  	cout << "No" << endl;
  }
}
