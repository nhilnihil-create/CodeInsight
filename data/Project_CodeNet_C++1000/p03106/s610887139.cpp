#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rept(i,s,n) for (int i = (s); i < (n); ++i)

#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;

int main() {

  int a, b, k;
  cin >> a >> b >> k;
    int cnt = 0;
    int i = 101;
    
    while(cnt<k && i>=1){
        --i;
        if(a%i==0 && b%i==0){
            cnt++;
        }
    }

  cout << i << endl;

  return 0;
}
