#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
   int n,a,b;
   string s;
   cin >> n >> a >> b;
   cout << min(b,a*n) << endl;
   return 0;
}
