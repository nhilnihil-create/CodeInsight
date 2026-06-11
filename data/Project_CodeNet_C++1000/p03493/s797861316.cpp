#include <bits/stdc++.h>
using namespace std;

int main() {
  //1が書かれたマスにビー玉を置く時、ビー玉がビー玉が置かれるマスの数を出力する。
	int s1s2s3;
	cin >> s1s2s3;
    
    //s1s2s3 = 101;

	int s1, s2,s3;
  	cin >> s1 >> s2 >> s3;
  
	s1 = s1s2s3 / 100;
 	s2 = s1s2s3 /10 - s1 * 10;
    s3 = s1s2s3 - (s1 * 100 + s2 * 10) ;
  
  	cout << (s1 + s2 + s3) << endl;
}
  