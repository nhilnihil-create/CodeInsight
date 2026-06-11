#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(){
  	string s, xs;
  cin >> s;
 	vector<int> xc(1);
  
  for(int i = 0; s.length()> i; i ++){
  	if(s[i] != 'x'){
      xs += s[i];
  		xc.push_back(0);
    }
    else xc[xc.size() - 1]++;
  }
  
  for(int i = 0; xs.length() > i; i++){
	if(xs[i] != xs[xs.length() - 1 - i]) {
	cout << -1 << endl;
      return 0;
    }
  }
	int ans = 0;
  for(int i = 0; xc.size() / 2 > i; i++){
  	ans += max(xc[i], xc[xc.size() - 1 - i]) - min(xc[i], xc[xc.size() - 1 - i]);
  }
  cout << ans << endl;
	return 0;
}