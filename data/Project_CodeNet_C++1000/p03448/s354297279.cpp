#include <iostream>
using namespace std;

int main(){
  int a,b,c,x;
  cin >> a >> b >> c >> x;
  int counter = 0;
  for(int A = 0;A<=a;A++){
    for(int B = 0;B<=b;B++){
      for(int C = 0;C<=c;C++){
        int total = 500*A + 100*B + 50*C;
        if(total == x){
          counter++;
        }
      }
    }
  }
  cout << counter << endl;
}
