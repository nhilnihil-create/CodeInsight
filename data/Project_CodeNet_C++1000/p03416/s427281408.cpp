#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B;
  cin >> A >> B;
  int ans = 0;
  for(int i = 0; i < B - A + 1; i++){
    int x = 0;
    bool t = true;
    int a = A + i;
    for(int n = 0;;n++){
    a = a / 10 ;
        if( a == 0){
          break;
        }
      x++;
    }
    vector<int>uuu(x + 1);
    int k; 
    k = A + i;
    for(int l = 0; l < x + 1; l++){
    uuu.at(l) = k -10*(k /10);
      k =k /10 ;
    }
    for(int u = 0; u < (uuu.size() + 1)/2; u++){
      if (uuu.at(u) != uuu.at(uuu.size() - u - 1 )){
        t = false;
      }
    }
      if(t){
        ans++;
    }
  }
  cout << ans << endl;
}