#include <bits/stdc++.h>
using namespace std;

long long indB, ans;
string s;

int main() {
	cin >> s;
	for(char ele: s){
      if(ele == 'B')
        indB++;
      else if(ele == 'W')
        ans += indB;
    }
	cout << ans << endl;
}