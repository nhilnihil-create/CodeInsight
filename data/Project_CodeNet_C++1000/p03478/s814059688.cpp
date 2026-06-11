#include <iostream>
using namespace std;

int main() {
	
 int n, a, b,len(0),tmp(0),ans(0);
  string s;
  cin >> n >> a >> b;
  
  for(int i = 1;i <= n;i++){
 	s = to_string(i);
    len = s.length();
    //cout << s << endl << len << "  ";
    for(int j = 0;j < len;j++){
      tmp += (int)s[j]-48;
      //cout << (int)s[j]-48 << endl;
    }
    if(tmp >= a && tmp <= b){
      ans += i;
    }
    tmp = 0;
    len = 0;
    s = " ";
  }
  
    cout << ans;
}
