#include <bits/stdc++.h>
using namespace std;

int main(){
    string c = "YES";
  	int cnt = 0;
	string s;
  	cin >> s;
    for(int i=0;i<s.size();i++){
      if(s.at(i)=='o')
        cnt++;
    }
  	if(8<=s.size()&&cnt<=s.size()-8)
      c = "NO";
    cout << c << endl;
}
