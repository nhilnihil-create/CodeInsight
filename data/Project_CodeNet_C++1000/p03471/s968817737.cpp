#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;




int main() {
  int n,y;
  cin >> n >> y;
  
  int r10000 = -1, r5000 = -1, r1000 = -1; 
  for(int i = 0; i <= n; i++){//10000
      for(int j = 0; i + j <= n; j++){//5000
        int c = n-i-j;//1000円札の枚数
        int ans = 10000*i + 5000*j + 1000*c;
        if(ans == y){
            r10000 = i;
            r5000 = j;
            r1000 = c;
        }
      }
  }
  cout << r10000 << " " << r5000 << " " << r1000 << endl;

}

