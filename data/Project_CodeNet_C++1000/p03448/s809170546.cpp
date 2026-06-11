#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  int A,B,C,X;
  cin >> A >> B >> C >> X;
  int sum = 0;
  int cnt = 0;
  bool f = false;

  for(int i = 0; i <= A; i++){
    for(int j = 0; j <= B; j++){
      for(int k = 0; k <= C; k++){
        sum = 500*i + 100*j + 50*k;
        if(sum == X){
          cnt++;
          f = true;
        }
      }
    }
  }

 if(f){
   cout << cnt << endl;
 }else{
   cout << 0 << endl;
 }


}



