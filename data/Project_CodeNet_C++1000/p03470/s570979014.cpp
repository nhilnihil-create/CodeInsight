#include <bits/stdc++.h>
using namespace std;

int N, A, brosky[105], michael=0, i;

int main () {
  cin >> N;
  for (int i=1;i<=N;i++){
    cin >> A;
    brosky[A]++;
  }
  //baca frekuensi sampai 100, karena bilangan dapat berupa puluhan dan seratus
  for(int num=1; num<=100; num++) {
    if(brosky[num]>0){
      michael++;
    }
  }
  cout << michael << endl;
} 
