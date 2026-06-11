#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i<b; i++)
typedef long long ll;
int main() {
    int n;
    cin >> n;
    
    string s = "";
    while(n != 0) {
      if (n % 2 != 0) {
        n--;
        s += "1";
      } else {
        s += "0";
      }
      n /= -2;
    }
    
    reverse(s.begin(), s.end());
    if (s == "") {
      s = '0';
    }
    
    cout << s << endl;
    return 0;
}