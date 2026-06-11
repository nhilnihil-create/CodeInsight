#include <bits/stdc++.h>
using namespace std;

int main() {
  int A = 0, B = 0;
  cin >> A >> B;
  int count = 0;
  int sum = B - A + 1;	//A-B間でとりえる整数の総数

  for( int i = 0; i < sum; ++i ){
    int iA = A + i;
    //1桁ずつ切り出す
    string strA = to_string( iA );
    if( strA[0] == strA[4] && strA[1] == strA[3] ){
      ++count;
    }
  }
  cout << count << endl;
}