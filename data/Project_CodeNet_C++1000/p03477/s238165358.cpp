#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
   int a,b,c,d;
   string s;
   cin >> a >> b >> c >> d;
   if (a+b > c+d) cout << "Left" << endl;
   else if (a+b == c+d) cout << "Balanced" << endl;
   else cout << "Right" << endl;
   return 0;
}
