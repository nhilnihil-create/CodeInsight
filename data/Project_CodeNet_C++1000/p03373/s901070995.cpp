#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int a,b,c;
    int x,y;
    int minxy;
    cin >> a >> b >> c >> x >> y;

    minxy = x;
    if(x > y) minxy = y;

    if(a > 2*c || b > 2*c){
      if(x > y && a > 2*c){
        cout << 2*c*x << endl;
      }else if(x < y && b > 2*c){
        cout << 2*c*y << endl;
      }else{
        cout << a*(x-minxy) + b*(y-minxy) + 2*c*minxy << endl;
      }
      return 0;
    }

    if (a + b < 2*c) {
      cout << a*x + b*y << endl;
    } else {
      cout << a*(x-minxy) + b*(y-minxy) + 2*c*minxy << endl;
    }

    return 0;
}
