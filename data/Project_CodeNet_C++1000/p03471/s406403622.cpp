#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N,Y;
  cin >> N >> Y;
  int one = -1, two = -1,three = -1;

  for(int i = 0; i <= N; i++){
    for(int j = 0; i+j <= N; j++){
      int k = N - i - j;//1000円札の枚数
      int total = 10000*i + 5000*j + 1000*k;
      if(total == Y){
        one = i;
        two = j;
        three = k;
      }
    }
  }
  cout << one << " " << two << " " << three << endl;

}