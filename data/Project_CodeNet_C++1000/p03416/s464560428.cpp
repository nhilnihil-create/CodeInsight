#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A,B;
  int cnt=0;
  cin >> A >> B;
  for (int i = A; i < B+1; i++){
    int a = i/10000;
    int b = i%10000/1000;
    int c = i%1000/100;
    int d = i%100/10;
    int e = i%10;
    int r = e*10000+d*1000+c*100+b*10+a*1;
    if (i==r)
      cnt +=1;
  }
  cout << cnt << endl;

}

