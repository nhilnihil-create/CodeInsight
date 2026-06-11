#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s; cin >> s;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (i % 2) {
    	cnt1 += s[i] == '0';
    	cnt2 += s[i] == '1';
    } else {
      	cnt1 += s[i] == '1';
    	cnt2 += s[i] == '0';
    }
  }
  cout << (cnt1 < cnt2 ? cnt1 : cnt2) << endl;
}