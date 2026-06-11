#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int a,b;
  cin >> a >>b;
  int ans = 0;
  rep2(i,a,b+1){
        int p=i/10000;
        int q=i%10;
        int r=(i-p*10000)/1000;
        int s=(i%100)/10;
        if (p==q && r==s) ++ans;
  }
  cout << ans << endl;
}