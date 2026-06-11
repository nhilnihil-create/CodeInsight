#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
   int a,b,c;
   string s;
   cin >> a >> b >> c;
   if (a+b == 2*a) cout << c<< endl;
   else if (a+c == a*2) cout << b << endl;
   else if (b+c == c*2) cout << a << endl;
   
   
   return 0;
   
}

