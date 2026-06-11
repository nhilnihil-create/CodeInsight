#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  int count = 0;
  for(int i=A; i<=B; i++){
    int a1 = i/10000;
    int a2 = i%10000/1000;
    int a3 = i%1000/100;
    if(i == a1*10000 + a2*1000 + a3*100 + a2*10 + a1){
      count ++;
    }
  }
  cout << count << endl;
}