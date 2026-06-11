#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B;
  int count = 0;
  
 
    int oneNum = 0;
    int tenNum = 0;
    int hundredNum = 0;
    int thousandNum = 0;
    int tThousandNum = 0;
   
  for (int i = 0; i < 10; i++) {
    tThousandNum = i * 10000;
    oneNum = i;
    for (int j = 0; j < 10; j++) {
      hundredNum = j * 100;
      for (int k = 0; k < 10; k++) {
        thousandNum = k * 1000;
        tenNum = k * 10;
        
        int num = tThousandNum + thousandNum + hundredNum + tenNum + oneNum;
        if (A <= num && num <= B) {
          count++;
        }
      }
    }
  }
  cout << count << endl;
}