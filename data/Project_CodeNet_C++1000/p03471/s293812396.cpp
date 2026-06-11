#include <iostream>
using namespace std;

int main(){
  int n,gold;
  int res10000=-1,res5000=-1,res1000=-1;
  cin >> n >> gold;
  for(int x = 0;x <= n;x++){
    for(int y = 0;x+y <= n;y++){
      int z = n - x - y;
      int total = 10000*x + 5000*y + 1000*z;
      if(total == gold){
        res10000 = x;
        res5000 = y;
        res1000 = z;
        
      }
    }
  }
  cout << res10000 << " " << res5000 << " " << res1000 << endl;
}
