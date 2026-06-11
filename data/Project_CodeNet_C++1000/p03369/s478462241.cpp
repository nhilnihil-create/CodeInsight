#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
 
int main(){
  int sum = 700;
  string x;
  cin >> x;
  rep(i, 3){
    if(x[i] == 'o'){
      sum += 100;
    }
  }
  cout << sum << endl;
}
